//---- Kullanılan Kütüphaneler ----//
#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
//---------------------------------//



//------ Global Değişkenler ------//
static unsigned long val1;
static char op;
static unsigned long val2;
static unsigned long result;
//--------------------------------//



/********************** Proc Sanal Dosyasından Okuma Fonksiyonu **********************/

static int procfile_read(char *buffer, char **start, off_t offset, int length)
{
	int size;
	size = sprintf(buffer, "%ld\n", result);
	*start = buffer + offset;
	size = size - offset;

	if(size>length)
	{
		return length;
	}

	else if (size>0)
	{
		return size;
	}

	else return 0;
}
/************************************************************************************/



/************************************ Proc Sanal Dosyasına Yazma Fonksiyonu ************************************/

static int procfile_write(struct file *file, const char __user *buff, unsigned long len, void *data)
{

	char buf[23]; // vals1(10) + boşluk(1) + islem(1) + boşluk(1) + vals2(10) = buf(23)
	char vals1[10], vals2[10]; // Maksimum 10 elemanlı sayılar kabul edildi.
	char *endp1, *endp2;

	if (len > sizeof(buf))
	{
		return -EINVAL;
	}

	if (copy_from_user(buf, buff, len)) // Data, "user katmanı"ndan katmanından "kernel katmanı"na katmanına kopyalandı.
	{
		return -EFAULT;
	}

//---------- Karakterleri çözümleyerek sayıları ve işlem operatörünü belirler ----------//
	int i;
	for(i=0; i<23; i++)
	{	
		if(buf[i]==' ')
		{
			i++;
			op = buf[i];
			i++;
			i++;
			int j, k=0;
			for(j=i; buf[j]!=NULL; j++)
			{
				vals2[k]=buf[j];
				k++;			
			}			
			break;
		}

		else	vals1[i]=buf[i];
	}
//--------------------------------------------------------------------------------------//

	val1= simple_strtoul(vals1, &endp1, 10); // Karakterler tanındıktan sonra, "char" tipinden "long"
	val2= simple_strtoul(vals2, &endp2, 10); // tipine dönüştürülerek uygun değişkenlere aktarılır.


//------------------------ Operatöre Göre Yapılacak İşlemi Belirleme ------------------------//
	switch(op){
		case '+' : result = val1 + val2; break;
		case '-' : result = val1 - val2; break;
		case 'x' : result = val1 * val2; break;
		case '/' : result = val1 / val2; break;
		default	 : break;
	}
//-------------------------------------------------------------------------------------------//

	printk (KERN_INFO "%ld %c %ld = %ld\n", val1, op, val2, result); // Yapılan işlemi "log"a yazar.
	return result;
}
/***************************************************************************************************************/



/************* "insmod" komutu ile çalışacak olan init fonksiyonu ****************/

static int __init dortislem_init(void)
{
	struct proc_dir_entry *proc_odevi;
	struct proc_dir_entry *proc_odevi_dortislem;

	proc_odevi = proc_mkdir("proc_odevi", 0); // "proc_odevi" adlı proc dizinini oluşturduk.
	
	if (!proc_odevi) {
		printk (KERN_ERR "Dizin oluşturulamadı!: /proc/proc_odevi\n");
		return -ENOMEM;
	}
	
	proc_odevi_dortislem = create_proc_read_entry("proc_odevi/dortislem", 0, NULL, procfile_read, &proc_odevi);// proc_odevi klasörünün içine dortislem sanal dosyasını oluşturduk.
	if (!proc_odevi_dortislem) {
		printk (KERN_ERR "Sanal dosya oluşturulamadı!: /proc/proc_odevi/dortislem\n");
		remove_proc_entry("proc_odevi", 0);
		return -ENOMEM;
	}
	proc_odevi_dortislem->write_proc = procfile_write;// dortislem dosyasına yazma işleminin yapılması "procfile_write" fonksiyonu ile belirleniyor.
	
	return 0;
}
/*********************************************************************************/



/************* "rmmod" komutu ile çalışacak olan cleanup (exit) fonksiyonu ****************/

static void __exit dortislem_exit(void)
{
	remove_proc_entry("proc_odevi/dortislem", 0);   // proc sanal dosyası
	remove_proc_entry("proc_odevi", 0);		// ve dizini silinir.
}
/*****************************************************************************************/
module_init(dortislem_init);
module_exit(dortislem_exit);

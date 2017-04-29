
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

#if 0
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include "md5.h"    

int main(int argc, char *argv[])  
{  



    int i;  
    unsigned char encrypt[] ="admin";//21232f297a57a5a743894a0e4a801fc3  
    unsigned char decrypt[16];      
    MD5_CTX md5;  
    MD5Init(&md5);                
    MD5Update(&md5,encrypt,strlen((char *)encrypt));  
    MD5Final(&md5,decrypt);          
    printf("加密前:%s\n加密后:",encrypt);  
    for(i=0;i<16;i++)  
    {  
        printf("%02x",decrypt[i]);  
    }  
     
	puts("");
    //getchar();  


      
    return 0;  
}  

#endif 



#if 0


#include <string.h>  /* strcpy */  
#include <stdlib.h>  /* malloc */  
#include <stdio.h>   /* printf */  
#include "uthash.h"  
  
typedef struct my_struct {  
    char domain[128];             /* key (string is WITHIN the structure) */  
    char ip[32]; 
    UT_hash_handle hh;         /* makes this structure hashable */  
}hashmap;  
  
  
int main(int argc, char *argv[]) {  
    const char **n1, *domains[] = { "joe", "bob", "betty", NULL }; 
	const char **n2, *ips[] = {"192.168.1.1", "192.168.1.2", "192.168.1.3", NULL};
    struct my_struct *s, *tmp, *users = NULL;  
    int i=0;  
  
    for (n1 = domains, n2 = ips; *n1 != NULL; n1++, n2++) {  
        s = (struct my_struct*)malloc(sizeof(struct my_struct));  
        strcpy(s->domain, *n1);  
		strcpy(s->ip, *n2);
        HASH_ADD_STR( users, domain, s );  
    }  
  	struct my_struct *ss=NULL;
    HASH_FIND_STR( users, "betty", ss);  
    if (ss) 
		printf("betty's ip is %s\n", ss->ip);  
  
    /* free the hash table contents  */ 
    HASH_ITER(hh, users, s, tmp) {  
      HASH_DEL(users, s);  
      free(s);  
    }  
    return 0;  
}  


#endif 

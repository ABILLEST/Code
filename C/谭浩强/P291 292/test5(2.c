#include <stdio.h> 

 int M; 

int main() 
{ 
    int n, s = 0,i;
    printf("���ٸ��ˣ� ");
	scanf("%d", &n);
	printf("�������ٵĳ��֣� ");
    scanf("%d", &M); 
    
    for (i = 2; i <= n; ++i) 
        s = (s+M)%i; 
    printf("%d\n", s+1); 
    return 0; 
}

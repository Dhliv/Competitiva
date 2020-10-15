/* @author pyeatt 
   Could be compressed into fewer lines
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
  int bytes;
  unsigned char *data;
};

struct data *getdata()
{ int i;
  int t;
  struct data *d = malloc(sizeof(struct data));
  scanf("%d",&(d->bytes));
  d->data = malloc(d->bytes*sizeof(unsigned char));
  for(i=0;i<d->bytes;i++)
    {
      scanf("%d",&t);
      d->data[i] = t;
    }
  return d;
}

int main()
{
  int n,m,p,q,i,j,k,l,r,type;
  unsigned char *a;
  struct data **x;
  
  scanf("%d%d%d",&n,&m,&q);

  a = malloc(n*sizeof(char));
  bzero(a,n*sizeof(char));

  x = malloc(q*sizeof(struct data *));
  for(j=0;j<m;j++)
    x[j] = getdata();

  for(j=0;j<q;j++)
    {
      scanf("%d",&type);
      switch(type)
	{
	case 1:
	  scanf("%d%d",&i,&p);
	  memcpy(a+p-1,x[i-1]->data,x[i-1]->bytes);
	  // or used slow copy:
	  // for(k=0;k<x[i-1]->bytes;k++)  
	  // a[p+k-1] = x[i-1]->data[k];
	  break;
	case 2:
	  scanf("%d",&p);
	  printf("%d\n",a[p-1]);
	  break;
	case 3:
	  scanf("%d%d%d",&i,&l,&r);
	  for(k=l-1;k<=r-1;k++)
	    x[i-1]->data[k]++;
	  break;
	}
    }

  free(a);
  for(j=0;j<m;j++)
    {
      free(x[j]->data);
      free(x[j]);
    }
  free(x);
  return 0;
}


# define size 50000
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <locale.h>
#include<iostream>
using namespace std;

class masiv 
{int mas1[size],mas[size];
public :
	void masiv::zapoln(){int i;
	for (i=0;i<size;i++)
	  {
	   mas1[i]=rand()%100 ;
	   mas[i]=mas1[i];
	  }
return ; }
	void rewrite(){
		int i;
for (i=0;i<size;i++)
	   mas[i]=mas1[i];
		return ;

}
void masiv::print(int n) 
{
 int i ;
     for(i=0;i<n;i++)
	   cout<<"\n"<<mas[i];
}
int poiskvub(int n, int p,int *iter);
int poisklin(int n,int p,int *iter);
void sortbuble(int *iter,int *obmen,int n);
void sortmin(int *iter,int *obmen,int n);
void sort(int *iter,int *obmen,int n);
void sortsl(int *iter,int *obmen,int mast[size],int n ,int k);
};
int masiv:: poiskvub(int n, int p,int *iter)
{
	iter=0;
int l=0,r=n-1,m;
while(l<=r)
{iter++;
	m=(r+l)/2;
if ( mas[m]==p)
{return m;
break;}
else
   if (mas[m]>p)
      r=m-1;
   if (mas[m]<p)
      l=m+1;
}
return(-1);}




int masiv ::poisklin(int n,int p,int *iter)
{iter=0;int i;
for(i=0;i<n;i++){
	iter++;
		if (mas[i]==p)
			return i ;}
return (-1);}

void masiv::sortbuble(int *iter,int *obmen,int n)
{iter=0;obmen=0;
	int i,j,k;
	for(i=n;i>0;i--)
	{
		for (j=0;(i-1)>j;j++)
		{ iter++;
			if (mas[j]>mas[j+1])
			{ obmen++;
				k=mas[j+1];
				mas[j+1]=mas[j];
				mas[j]=k;
			}
		}
	}
	return;
}
void masiv::sortmin(int *iter,int *obmen,int n)
{iter=0;obmen=0;
	int i,j,d,c,min;
for(i=0;i<n-1;i++)
	{
		min=mas[i];
		d=i;
		for (j=i;n>j;j++)
		{iter++;
			if (min > mas[j])
			{ obmen++;
				min=mas[j];
				d=j;
			}
		}
			c = mas[i];
			mas[i] = min;
			mas[d] = c;
		
} return;
}

void masiv::sort(int *iter,int *obmen,int n)
{iter=0;obmen=0;int i,j,pos,a1;
for (i=1;i<n;i++)
{
	pos=-1;
    for (j=i-1;j>=0;j--)
        {iter++;
         if (mas[i]>mas[j])
           {obmen++;
            pos=j;
            break;
           }
    }
	a1=mas[i];
for(j=i-1;pos<j;j--)
{
	mas[j+1]=mas[j];
}
mas[pos+1]=a1;
}
}

void sl(int *iter,int *obmen,int mas[size],int mast[size],int n1 ,int k1,  int n2 ,int k2)
{iter=0;obmen=0; n1-=1;n2-=1;k1-=1;k2-=1;
	int i=n1 ,j= n2 ,k=n1,l ;
while((i<=k1)&&(j<=k2))
{ iter++;
	if( mas[i]<mas[j])
	{
		mast[k] = mas[i];
		i++;
		k++;
		obmen++;
	}
	else
	{
		mast[k]= mas[j];
	j++;
	k++;
	obmen++;}
}if (i<=k1)
		for (i;i<=k1;i++)
		{
			mast[k]=mas[i];
			k++;obmen++;
		}
	else
		for (j;j<=k2;j++)
		{mast[k]=mas[j];
	k++;obmen++;
	}for (l=n1;l<=k2;l++)
		mas[l]=mast[l];
}

void masiv::sortsl(int *iter,int *obmen,int mast[size],int n ,int k)
{int s ;
if(n==k) {return ;}
s=(n+k)/2;

masiv.sortsl( iter,obmen,mast,n,s);
masiv.sortsl( iter,obmen,mast,s+1,k);
sl(iter,obmen,mas,mast,n,s,s+1,k);

}
void main ()
{
   clock_t start, finish;
	int n=20,g=1,t=size,j,p,mast[size],k,m,*iter,*obmen;
	double duration1,duration2,duration3,duration4;
	masiv M ;
    setlocale(LC_CTYPE,"Russian");
  cout<<"1-заполнение массива\n2-запись массива\n3-сортировка массива\n4-сортировка минимальными\n5-сортировка вставкой\n6-перезапись\n7-поиск бинарного\n8-поиск линейный\n9-сортировка слиянием\n10-очистка экрана\n11-выход\n";
	while (g!=0){
	
	cin>>g;
	switch(g)
	{
	case 1: M.zapoln();
		break;
	case 2:cout<<"введите номер до которого хотите записать но учтите что массив будет записываться до 25 элемента\n";
		cin>>n; 
		if (n<=25)
			M.print(n);
		else
			cout<<"введите другой номер\n";
		break;
	case 3 : 
		cout<<"введите позицию до которой хотите сортировать массив\n";
		cin>>n;
		start = clock();
	    M.sortbuble(iter,obmen,n);
        finish = clock();duration1 = (double)(finish - start) / CLOCKS_PER_SEC;
		cout<<"seconds\n"<<duration1;
		cout<<"число сравнений  "<<iter<< "\n число обменов "<<obmen <<"\n";
		break;
	
	case 4:
		cout<<"введите позицию до которой хотите сортировать массив \n ";
		cin>>n ;
		start = clock();
	    
		M.sortmin(iter,obmen,n);
        finish = clock();duration2 = (double)(finish - start) / CLOCKS_PER_SEC;
		cout<<"seconds\n"<<duration2;
		cout<<"число сравнений  "<<iter<< "\n число обменов "<<obmen <<"\n";
		break;
	case  5 :
		cout<<"введите позицию до которой хотите сортировать массив\n"; 
		cin>>n;
		start = clock();
	    M.sort(iter,obmen,n);
        finish = clock();
	    duration3 = (double)(finish - start) / CLOCKS_PER_SEC;
		cout<<"seconds\n"<<duration3;
		cout<<"число сравнений  "<<iter<< "\n число обменов "<<obmen <<"\n";
		break;
		case 6:
			M.rewrite();
			break;
		case 7:
			cout<<"перед поиском сортируйте массив ,введите число и введите до какой позиции искать\n ";
			cin>>p>>n;
			j=M.poiskvub(n,p,iter);
			if (j!=-1)
			     { cout<<"даное число находиться под номером"<<j+1<<"  \n" ;
			     cout<<"число сравнений "<<iter<<" \n ";}
			else
				cout<<"данного числа нет\n ";
			break;
		case 8:
			cout<<"введите число и введите до какой позиции искать ";
			cin>>p>>n;
			j=M.poisklin(n,p,iter);
			if (j!=-1) 
			   {cout<<"даное число находиться под номером"<<j+1<<"  \n" ;
			     cout<<"число сравнений "<<iter<<" \n ";
			    }
			else 
				cout<<"данного числа нет ";break;
		case 9:cout<<"введите позицию с которой хотите сортировать массив  и до которой хотите сортировать массив \n "; cin>>m>>k;
			start = clock();

     M.sortsl(iter,obmen,mast,m,k);
    finish = clock();duration4 = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"seconds\n"<<duration4;
		cout<<"число сравнений  "<<iter<< "\n число обменов "<<obmen <<"\n";
	break;

		case 10:system("cls");
			
			cout<<"1-заполнение массива\n2-запись массива\n3-сортировка массива\n4-сортировка минимальными\n5-сортировка вставкой\n6-перезапись\n7-поиск бинарного\n8-поиск линейный\n9-сортировка слиянием\n10-очистка экрана\n11-выход\n";
			break;
     case 11: g=0 ;break;
	default:
		cout<<"введите номер\n";
		break;

	}
	}
}
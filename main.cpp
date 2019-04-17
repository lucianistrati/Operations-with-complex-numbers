#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("date.in",ios::in);
ofstream fout("date.out",ios::out);
const int capacitate_maxima=1073741823;
class NumarComplex
{
private:
  float re,im;
public:
  NumarComplex(){ re=0; im=0; }
  ~NumarComplex(){}
  void setter_real(float d);
  void setter_imaginary(float d);
  float getter_real(NumarComplex a);
  float getter_imaginary(NumarComplex a);
  float modul_complex(NumarComplex a);
  friend istream & operator >>(istream & in, NumarComplex &a);
  friend ostream & operator <<(ostream & out,const NumarComplex a);
  NumarComplex operator=(NumarComplex a);
  bool operator ==(NumarComplex a);
  bool operator <(NumarComplex a);
  bool operator !=(NumarComplex a);
  NumarComplex operator+(NumarComplex a);
  NumarComplex operator-(NumarComplex a);
  NumarComplex operator*(NumarComplex a);
  NumarComplex operator/(NumarComplex a);
  NumarComplex suma_complex(NumarComplex a,NumarComplex b);
  NumarComplex diferenta_complex(NumarComplex a,NumarComplex b);
  NumarComplex produs_complex(NumarComplex a,NumarComplex b);
  NumarComplex impartire_complex(NumarComplex a,NumarComplex b);
  void afisare();
  friend class VectorNumereComplexe;
};
void NumarComplex::afisare()
{
  cout<<re<<" + "<<im<<"*i";
}
float NumarComplex::modul_complex(NumarComplex a)
{
   float r;
   r=sqrt(a.re*a.re+a.im*a.im);
   return r;
}
istream & operator >>(istream & in, NumarComplex &a)
{
  in>>a.re>>a.im;
  return in;
}
ostream & operator <<(ostream & out,const NumarComplex a)
{
  out<<a.re<<" + "<<a.im<<"*i\n";
  return out;
}
void NumarComplex::setter_real(float d)
{
  re=d;
}
void NumarComplex::setter_imaginary(float d)
{
  im=d;
}
float NumarComplex::getter_real(NumarComplex a)
{
  return a.re;
}
float NumarComplex::getter_imaginary(NumarComplex a)
{
  return a.im;
}
NumarComplex NumarComplex:: operator=(NumarComplex a)
{
  re=a.re;
  im=a.im;
  return (*this);
}
bool NumarComplex:: operator==(NumarComplex a)
{
    return (a.re==re && a.im==im);
}
bool NumarComplex:: operator<(NumarComplex a)
{
     return (sqrt(re*re+im*im)<modul_complex(a));
}
bool NumarComplex::operator!=(NumarComplex a)
{
      return (a.re!=re || a.im!=im);
}
NumarComplex NumarComplex::operator+(NumarComplex a)
{
   NumarComplex c;
   c.setter_real(0);
   c.setter_imaginary(0);
   c.re=re+getter_real(a);
   c.im=im+getter_imaginary(a);
   return c;
}
NumarComplex NumarComplex::operator-(NumarComplex a)// const
{
   NumarComplex c;
   c.setter_real(0);
   c.setter_imaginary(0);
   c.re=re-getter_real(a);
   c.im=im-getter_imaginary(a);
   return c;
}
NumarComplex NumarComplex::operator*(NumarComplex a)// const
{
   NumarComplex c;
   c.re=re*getter_real(a)-im*getter_imaginary(a);
   c.im=im*getter_real(a)+re*getter_imaginary(a);
   return c;
}
NumarComplex NumarComplex::operator/(NumarComplex a)// const
{
   NumarComplex c;
   float t;
   int verif;
   t=getter_real(a)*getter_real(a)+getter_imaginary(a)*getter_imaginary(a);
   try
   {
      if(t==0)
      {
         throw "eroare";
      }
   }
   catch(...)
   {
        cout << "EROARE! S-a incercat impartirea la zero!";
        verif=-1;
        exit(0);
   }
   if(verif!=-1)
   {
        c.re=(re*getter_real(a)+im*getter_imaginary(a))/t;
        c.im=(im*getter_real(a)-re*getter_imaginary(a))/t;
        return c;
   }
}
NumarComplex suma_complex(NumarComplex a,NumarComplex b)
{
   a=a+b;
   return a;
}
NumarComplex diferenta_complex(NumarComplex a,NumarComplex b)
{
   a=a-b;
   return a;
}
NumarComplex produs_complex(NumarComplex a,NumarComplex b)
{
  a=a*b;
  return a;
}
NumarComplex impartire_complex(NumarComplex a,NumarComplex b)
{
  a=a/b;
  return a;
}
class VectorNumereComplexe
{
   private:
    int dimensiune;
    NumarComplex *a;
   public:
       VectorNumereComplexe operator=(VectorNumereComplexe v);
        VectorNumereComplexe operator*(VectorNumereComplexe v);
       VectorNumereComplexe operator+(VectorNumereComplexe v);
       void insert_all_data();
       void fisier_insert_all_data();
       void setter_pos(NumarComplex t,int i);
       NumarComplex getter_pos(int i);
       void setter_dimensiune(int n);
       int getter_dimensiune();
   VectorNumereComplexe()
   {
       dimensiune=0;
       a=NULL;
   }
   ~VectorNumereComplexe()
   {
       delete[] a;
   }
   friend float modul_complex(NumarComplex a);
   void SortareDupaModule();
   NumarComplex SumaVectorNumereComplexe();
   NumarComplex ProdusulScalarDoiVectori(VectorNumereComplexe t);
   friend istream & operator >>(istream & in, VectorNumereComplexe &v);
  friend ostream & operator <<(ostream & out,const VectorNumereComplexe v);
   NumarComplex & operator[](int i);
   virtual void adaugare_pos(NumarComplex x,int pos)
{

    dimensiune++;
    NumarComplex *a2=new NumarComplex[dimensiune];

    //a=new NumarComplex[dimensiune];
    for(int i=0;i<dimensiune;i++){
        a2[i]=a[i];
    }
    for(int i=dimensiune-1;i>=pos+1;i--){
        a2[i]=a2[i-1];
    }
    a2[pos]=x;
    delete []a;
    a=a2;
}
virtual void stergere_pos(int pos,int &dimensiune)
{
    int i;
    for(i=pos;i<dimensiune-1;i++)
    {
        a[i]=a[i+1];
    }
    dimensiune--;
}
};

istream & operator >>(istream & in, VectorNumereComplexe &v)
{
   in>>v.dimensiune;
   v.a=new NumarComplex[v.dimensiune];
   for(int i=0;i<v.dimensiune;i++)
   {
       in>>v.a[i];
   }
   return in;
}
ostream & operator <<(ostream & out,const VectorNumereComplexe v)
{
  for(int i=0;i<v.dimensiune;i++)
  {
      out<<v.a[i];
  }
  return out;
}

void VectorNumereComplexe::insert_all_data()
{
    cin>>dimensiune;
    a=new NumarComplex[dimensiune];
    for(int i=0;i<dimensiune;i++)
    {
        cin>>a[i];
    }
}
void VectorNumereComplexe::fisier_insert_all_data()
{
    fin>>dimensiune;
    a=new NumarComplex[dimensiune];
    for(int i=0;i<dimensiune;i++)
    {
        fin>>a[i];
    }
}
void VectorNumereComplexe::setter_pos(NumarComplex t,int i)
{
    a[i]=t;
}
NumarComplex VectorNumereComplexe::getter_pos(int i)
{
 return a[i];
}
VectorNumereComplexe VectorNumereComplexe::operator*(VectorNumereComplexe v)
{
    for(int i=0;i<dimensiune;i++)
    {
        a[i]=a[i]*v.a[i];
    }
    return (*this);
}
VectorNumereComplexe VectorNumereComplexe::operator+(VectorNumereComplexe v)
{
    for(int i=0;i<dimensiune;i++)
    {
        a[i]=a[i]+v.a[i];
    }
    return (*this);
}
VectorNumereComplexe VectorNumereComplexe::operator=(VectorNumereComplexe v)
{
     for(int i=0;i<dimensiune;i++)
     {
        a[i]=v.a[i];
     }
     return (*this);
}
void VectorNumereComplexe::setter_dimensiune(int n)
{
    dimensiune=n;
}
int VectorNumereComplexe::getter_dimensiune()
{
    return dimensiune;
}
NumarComplex & VectorNumereComplexe :: operator[](int i)
{
   if(i>=0 && i<dimensiune)
   {
      getter_pos(i);
   }

}
void VectorNumereComplexe::SortareDupaModule()
{
  int i,j;
  sort(a,a+dimensiune);
}
NumarComplex VectorNumereComplexe::SumaVectorNumereComplexe()
{
   NumarComplex s,t;
   s.setter_real(0);
   s.setter_imaginary(0);
   int i;
   for(i=0;i<dimensiune;i++)
   {
      s=s+a[i];
   }
   return s;
}
NumarComplex VectorNumereComplexe::ProdusulScalarDoiVectori(VectorNumereComplexe t)
{
   NumarComplex s;
   int i,j,k=0;
   //v.insert_all_data();
   //t.insert_all_data();
 //  res.a=new NumarComplex[t.getter_dimensiune()];//*v.getter_dimensiune()];
   for(i=0;i<dimensiune;i++)
   {
    //  for(j=0;j<t.getter_dimensiune();j++)
      //{
       NumarComplex l;
       a[i]=a[i]+a[i]*t.a[i]; //res.a[k]=res.a[k]+v.a[i]*t.a[j];
       k++;
     // }
   }
   for(i=0;i<dimensiune/*t.getter_dimensiune()*/;i++)
   {
       s=s+a[i];
     // cout<<res.a[i];
   }
   return s;
}
class Stiva:public VectorNumereComplexe//,public NumarComplex
{
private:
    int capacitate;
    int dim;
    NumarComplex *b;
    public:
    Stiva operator=( Stiva v);
    Stiva operator==(const Stiva & v);
   // NumarComplex operator=(NumarComplex a);
    friend istream & operator >>(istream & in, Stiva &v);
  friend ostream & operator <<(ostream & out, Stiva &v);
   NumarComplex varf();
    Stiva(int x=100001)
    {
        dim=0;
        capacitate=x;
        b=new NumarComplex[10];
    }
//    Stiva()
//    {
//        dim=0;
//        capacitate=100001;
//        b=NULL;
//    }
    ~Stiva()
    {
          delete[] b;
    }
    void adaugare(NumarComplex A);
    void stergere();
};
NumarComplex Stiva::varf()
{
    if(b==NULL){
        cout<<"NASPA"<<endl;
    }
    return b[dim-1];
}
Stiva Stiva::operator==(const Stiva & v)
{
    return (b==v.b);
}
Stiva Stiva::operator=(Stiva v)
{
    if(this->b==v.b)
    {
        return (*this);
    }
    delete[]b;
    capacitate=v.capacitate;
    dim=v.dim;
    b=new NumarComplex[dim];
    for(int i=0;i<dim;i++)
    {
        b[i]=v.b[i];
    }
    return (*this);
}
istream & operator >>(istream & in, Stiva &v)
{
    NumarComplex aux;
    int i;
    in>>v.dim;
    for(i=0;i<v.dim;i++)
    {
        in>>aux;
        v.adaugare(aux);
    }
    return in;
}
ostream & operator <<(ostream & out, Stiva &v)
{
    for(int i=v.dim-1;i>=0;i--){
        out<<v.b[i];
    }
    out<<'\n';
    return out;
}
void Stiva::adaugare(NumarComplex A)
{
    if(dim>capacitate)
    {
        cout<<"Overflow";
        exit(0);
    }
    else
    {
        NumarComplex *b2=new NumarComplex[dim+1];
        for(int i=0;i<dim;i++){
            b2[i]=b[i];
        }
        b2[dim]=A;
        dim++;
        delete[]b;
        b=b2;
    }
}
void Stiva::stergere()
{
    if(dim==0)
    {
        cout<<"Underflow";
        exit(0);
    }
    else
    {
        NumarComplex *b2=new NumarComplex[dim-1];
        for(int i=0;i<dim-1;i++)
        {
            b2[i]=b[i];
        }
        delete[]b;
        dim--;
        b=b2;
    }
}
class Coada:public VectorNumereComplexe
{
private:
    int capacitate;
    int dim;
    NumarComplex *b;
    public:
    friend istream & operator >>(istream & in, Coada &v);
  friend ostream & operator <<(ostream & out, Coada &v);
    Coada operator=(Coada v);
    NumarComplex fata();
    Coada(int x=100001)
    {
        dim=0;
        capacitate=100001;
        b=NULL;
    }
    ~Coada()
    {
        delete[] b;
    }
    void adaugare(NumarComplex A);
    void stergere();
};
Coada Coada::operator=(Coada v)
{
    if(this->b==v.b)
    {
        return (*this);
    }
    delete []v.b;
    capacitate=v.capacitate;
    dim=v.dim;
    for(int i=0;i<dim;i++)
    {
        b[i]=v.b[i];
    }
    return (*this);
}
istream & operator >>(istream & in, Coada &v)
{
    NumarComplex aux;
    int i;
    for(i=0;i<v.dim;i++)
    {
        in>>aux;
        v.adaugare(aux);
    }
    return in;
}
ostream & operator <<(ostream & out,Coada &v)
{
    for(int i=v.dim-1;i>=0;i--){
        out<<v.b[i];
    }
    out<<'\n';
    return out;
}
NumarComplex Coada::fata()
{
    return b[0];
}
void Coada::adaugare(NumarComplex A)
{
    if(dim==capacitate)
    {
        cout<<"Overflow";
        exit(0);
    }
    else
    {
        NumarComplex *b2=new NumarComplex[dim+1];
        for(int i=0;i<dim;i++)
        {
            b2[i]=b[i];
        }
        b2[dim]=A;
        dim++;
        delete[]b;
        b=b2;
    }

}
void Coada::stergere()
{
    if(dim==0)
    {
        cout<<"Underflow";
        exit(0);
    }
    else
    {
        NumarComplex *b2=new NumarComplex[dim-1];
        for(int i=0;i<dim-1;i++)
        {
            b2[i]=b[i+1];
        }
        delete[]b;
        dim--;
        b=b2;
    }
}
int main()
{
   int optiune=1,optiune2=1,optiune0;
   if(fin==NULL)
   {
       cout<<"Eroare la deschiderea fisierului de intrare";
       return 0;
   }
   if(fout==NULL)
   {
       cout<<"Eroare la deschiderea fisierului de iesire";
       return 0;
   }
   cout<<"Doriti citirea datelor si afisarea lor in fisier?\n";
   cout<<"1.NU                                         2.DA\n";
   cin>>optiune0;
   if(optiune0==1)
   {
   while(optiune==1 || optiune==2 || optiune2==1 || optiune2==2)
   {
       cout<<"Ce operatii doriti sa realizati?\n";
       cout<<"1.Pentru operatii cu numere complexe\n";
       cout<<"2.Pentru operatii cu vectori de numere complexe\n";
       cout<<"3.Pentru operatii cu stive de numere complexe\n";
       cout<<"4.Pentru operatii cu cozi de numere complexe\n";
       cin>>optiune;
   if(optiune==1)
   {
   NumarComplex a,b;
   cin>>a;
   cin>>b;
   cout<<a+b;
   cout<<a-b;
   cout<<a*b;
   cout<<a/b;
   }
   else if(optiune==2)
   {
   int i;
   VectorNumereComplexe v_sum,v,t,res;

 //   v_sum.insert_all_data();
   cin>>v_sum;
   cout<<"Suma vectorului v_sum este "<<v_sum.SumaVectorNumereComplexe()<<'\n';

   v_sum.SortareDupaModule();
   cout<<v_sum;
   /*for(i=0;i<v_sum.getter_dimensiune();i++)
   {
       cout<<v_sum.getter_pos(i);
   }*/
   cin>>v>>t;
   cout<<'\n';
   cout<<v.ProdusulScalarDoiVectori(t);
   }
   else if(optiune==3)
   {
       Stiva S;
       NumarComplex a,b,c,d;
       a.setter_real(1);
       a.setter_imaginary(1);
       b.setter_real(2);
       b.setter_imaginary(2);
       c.setter_real(3);
       c.setter_imaginary(3);
       d.setter_real(4);
       d.setter_imaginary(4);
       S.adaugare(a);
       S.adaugare(b);
       S.adaugare(c);
       cout<<S;
       S.stergere();
       cout<<S;
       S.adaugare(d);
       cout<<S;
   }
   else if(optiune==4)
   {
       Coada C;
       NumarComplex a,b,c,d;
       a.setter_real(1);
       a.setter_imaginary(1);
       b.setter_real(2);
       b.setter_imaginary(2);
       c.setter_real(3);
       c.setter_imaginary(3);
       d.setter_real(4);
       d.setter_imaginary(4);
       C.adaugare(a);
       C.adaugare(b);
       C.adaugare(c);
       cout<<C;
       C.stergere();
       cout<<C;
       C.adaugare(d);
       cout<<C;
   }
   else
   {
   cout<<"\nNu ati inserat 1,2,3 sau 4\n";
   }
   cout<<"\nMai doriti alte operatii?\n";
   cout<<"\n1.NU         2.DA\n";
   cin>>optiune2;
   if(optiune2==1)
   {
       return 0;
   }
   }
   }
   else
   {
       while(optiune==1 || optiune==2 || optiune2==1 || optiune2==2)
   {
       cout<<"Ce operatii doriti sa realizati?\n";
       cout<<"1.Pentru operatii cu numere complexe\n";
       cout<<"2.Pentru operatii cu vectori de numere complexe\n";
       cout<<"3.Pentru operatii cu stive de numere complexe\n";
       cout<<"4.Pentru operatii cu cozi de numere complexe\n";
       fin>>optiune;
   if(optiune==1)
   {
   NumarComplex a,b;
   fin>>a;
   fin>>b;
   fout<<a+b;
   fout<<a-b;
   fout<<a*b;
   fout<<a/b;
   }
   else if(optiune==2)
   {
   int i;
   VectorNumereComplexe v_sum,v,t,res;

 //  v_sum.fisier_insert_all_data();
   fin>>v_sum;
   fout<<"Suma vectorului v_sum este "<<v_sum.SumaVectorNumereComplexe()<<'\n';


   v_sum.SortareDupaModule();
   fout<<v_sum;
   /*for(i=0;i<v_sum.getter_dimensiune();i++)
   {
       fout<<v_sum.getter_pos(i);
   }*/
   fin>>v>>t;
   fout<<'\n';
   fout<<v.ProdusulScalarDoiVectori(t);
   }
   else if(optiune==3)
   {
       Stiva S;
       NumarComplex a,b,c,d;
       a.setter_real(1);
       a.setter_imaginary(1);
       b.setter_real(2);
       b.setter_imaginary(2);
       c.setter_real(3);
       c.setter_imaginary(3);
       d.setter_real(4);
       d.setter_imaginary(4);
       S.adaugare(a);
       S.adaugare(b);
       S.adaugare(c);
       fout<<S;
       S.stergere();
       fout<<S;
       S.adaugare(d);
       fout<<S;
   }
   else if(optiune==4)
   {
       Coada C;
       NumarComplex a,b,c,d;
       a.setter_real(1);
       a.setter_imaginary(1);
       b.setter_real(2);
       b.setter_imaginary(2);
       c.setter_real(3);
       c.setter_imaginary(3);
       d.setter_real(4);
       d.setter_imaginary(4);
       C.adaugare(a);
       C.adaugare(b);
       C.adaugare(c);
       fout<<C;
       C.stergere();
       fout<<C;
       C.adaugare(d);
       fout<<C;
   }
   else
   {
   fout<<"\nNu ati inserat 1,2,3 sau 4\n";
   }
   fin.close();
   fout.close();
       return 0;
   }
   }
   return 0;
}

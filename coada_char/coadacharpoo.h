#ifndef COADACHARPOO_H_INCLUDED
#define COADACHARPOO_H_INCLUDED

#include<iostream>
#include<cstring>
#include "nodchar.h"
using namespace std;
class coada{
protected:
    nod *prim,*ultim;
    int dim_max;
public:
    coada(char *c){
        prim=new nod(c);
        prim->next=ultim;
        ultim=NULL;
        dim_max=5;
    }
    coada(nod *prim,nod* ultim):prim(prim),ultim(ultim),dim_max(dim_max){
        prim=new nod();
        prim->info=NULL;
        prim->next=ultim;
        ultim=NULL;
        dim_max=5;
    }
    coada():prim(prim),ultim(ultim),dim_max(dim_max){
        prim=new nod();
        prim->info=NULL;
        prim->next=ultim;
        ultim=NULL;
        dim_max=5;
    }
    virtual ~coada(){
        nod *p;
        while(prim){
            p=prim;
            //cout<<"sterg "<<p->getinfo()<<endl;
            delete p;
            prim=prim->getnext();
        }
    }
    coada(const coada* ob):prim(ob->prim),ultim(ob->ultim),dim_max(ob->dim_max){}
    void add(char* c){
    if(prim==NULL){
        //cout<<"se creaza un nou prim"<<endl;
        prim=new nod(c);
        //cout<<"am adaugat "<<prim->getinfo()<<endl;
        return;
    }
    if(prim->info==NULL){
    //cout<<"vibe check"<<endl;
    prim->info=new char;
    for(int i=0;i<=strlen(c);i++)
        {
            //cout<<info[i]<<" "<<c[i]<<endl;
            prim->info[i]=c[i];
        }
    return;
    }
    if(ultim==NULL){
        //cout<<"se creaza un ultim"<<endl;
        //cout<<c<<" ultim ";
        ultim=new nod(c);
        prim->next=ultim;
        //cout<<prim->getinfo()<<" "<<ultim->getinfo()<<endl;
        return;
    }
    //cout<<c<<" simplu ";
    nod *p;
    p=new nod(c);
    ultim->next=p;
    ultim=p;
    //ultim->afis();
    }
    void trycitire(char* p){
    int lim=1;
    char *c;
    try {
            c=strtok(p," ");
            while(c!=NULL)
            {
                add(c);
                //cout<<c<<" dim max: "<<a->dim_max<<endl;
                c=strtok(NULL," ");
                lim++;
                if(lim>=dim_max)throw c;
            }
        }
        catch(char* c){
        cout<<"Prea multe cuvinte introduse; Se taie din coada..."<<endl;
        delete c;
        }
    delete c;
    }
    bool dimcheck();
    bool dimcheckplus(int);
    friend istream& operator >>(istream&,coada*);
    friend ostream& operator <<(ostream&,coada*);
    coada& operator =(const coada&);
    coada& operator [](int);
    virtual void pop()=0;
    virtual void erasee()=0;
    virtual char* top()=0;
    virtual void addpoz(char*,int)=0;
    //friend class vct;
};
bool coada::dimcheckplus(int poz){
    if(poz>dim_max)return 1;
    return 0;
}
bool coada::dimcheck(){
    nod* p;
    int i=1;
    for(p=prim;p!=NULL;p=p->getnext())i++;
    if(i>=dim_max)return 0;
    return 1;
    }
coada& coada::operator[](int i)
{
    if(i>=dim_max)
    {
        cout<<"nope"<<endl;
        exit(0);
    }
    return this[i];
}
istream& operator >>(istream& in, coada *a)
{
    string s;
    getline(in,s);
    char *c,p[101];
    //p=new char[s.size()+1];
    strcpy(p,s.c_str());
    a->trycitire(p);
    /*while(c!=NULL)
    {
        a->add(c);
        //cout<<c<<" dim max: "<<a->dim_max<<endl;
        c=strtok(NULL," ");
    }*/
    delete p;
    delete c;
    return in;

}
ostream& operator <<(ostream& out, coada *a){
nod *p;
if(!a->prim)return out;
//cout<<"incerc sa afisez"<<endl;
if(a->prim->getnext()==NULL){
    out<<a->prim;
    return out;
    }
for(p=a->prim;p!=NULL;p=p->getnext())
    out<<p<<" ";
//out<<a.ultim->getinfo();
return out;
}
coada& coada:: operator=(const coada &a)
{
    //char c;
    if(a.prim==NULL){
        this->prim=NULL;
        this->ultim=NULL;
        return *this;
    }
    if(a.ultim==NULL){
        this->prim=new nod(a.prim->info);
        this->ultim=NULL;
        return *this;
    }
        //c=a.prim->getinfo();
        //this->prim->val(c);
        //cout<<"lmao"<<endl;
        //this->ultim->val(a.ultim->getinfo());
    nod *p,*u;
        //cout<<"lmao"<<endl;
    this->prim=new nod(a.prim->info);
    p=a.prim->next;
    this->ultim=new nod(p->info);
    this->prim->next=this->ultim;
        //cout<<this->prim<<this->ultim<<endl;
        //nod *p,*u;
    for(p=p->next;p!=NULL;p=p->next)
    {
        u=new nod(p->info);
            //cout<<u->getinfo()<<" ";
        this->ultim->next=u;
            //cout<<ultim->getinfo()<<" ";
        ultim=u;
            //cout<<ultim->getinfo()<<endl;

    }
        //this->dim_max=a.dim_max;
        //this->prim=a.prim;
        //this->ultim=a.ultim;
    return *this;
}
class coadaTry{

};
#endif // COADACHARPOO_H_INCLUDED

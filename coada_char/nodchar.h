#ifndef NODCHAR_H_INCLUDED
#define NODCHAR_H_INCLUDED
#include<iostream>
#include<cstring>
//#include "coadacharpoo.h"
using namespace std;
class nod{
protected:
    char* info;
    nod* next;
public:
    nod(char *c){
    info=new char;
    for(int i=0;i<=strlen(c);i++)
        {
            //cout<<info[i]<<" "<<c[i]<<endl;
            info[i]=c[i];
        }
    //cout<<info<<endl;
    next=NULL;
    }
    //nod(char *info,nod *next):info(info),next(next){}
    /*nod(const nod* ob):info(ob->info),next(ob->next){
    this->info=new char;
    for(int i=0;i<=strlen(ob->info);i++)
        {
            //cout<<info[i]<<" "<<c[i]<<endl;
            this->info[i]=ob->info[i];
        }
    //cout<<info<<endl;
    //this->next=NULL;
    }*/
    nod(){
    info=new char;
    next=NULL;
    }
    nod(const nod* ob){
    this->info=new char;
    for(int i=0;i<=strlen(ob->info);i++)
        {
            //cout<<info[i]<<" "<<c[i]<<endl;
            this->info[i]=ob->info[i];
        }

    }
    ~nod(){
    delete info;
    }
    void urm(nod* ob){
    this->next=ob;
    }
    nod* getnext(){
    return this->next;
    }
    char* getinfo(){
    return this->info;
    }
    friend istream& operator >>(istream&,nod*);
    friend ostream& operator <<(ostream&,nod*);
    nod* operator =(const nod*);
    friend class coada;
};
istream& operator >>(istream& in,nod* ob)
{
    in>>ob->info;
    return in;
}
ostream& operator <<(ostream& out,nod* ob)
{
    out<<ob->info;
    return out;
}
nod* nod::operator =(const nod *ob){
        int n=strlen(ob->info);
        this->info=new char;
        for(int i=0;i<n;i++)
            this->info[i]=ob->info[i];
        this->next=ob->next;
        return this;
    }

#endif // NODCHAR_H_INCLUDED

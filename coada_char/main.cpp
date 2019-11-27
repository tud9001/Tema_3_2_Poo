#include<iostream>
#include<cstring>
#include "nodchar.h"
#include "coadacharpoo.h"
using namespace std;
class DEQUE:public coada{
public:
    DEQUE(nod *prim,nod* ultim):coada(prim,ultim){}
    DEQUE(const DEQUE* ob):coada(ob->prim,ob->ultim){}
    /*~DEQUE(){
    nod *p;
        while(prim){
            p=prim;
            //cout<<"sterg "<<p->getinfo()<<endl;
            delete p;
            prim=prim->getnext();
        }
    }*/
    char* top(){
    try{
    if(prim==NULL)throw "coada este goala";
    }
    catch(const char *c){
    return const_cast<char*>(c);
    }
    return prim->getinfo();
    }
    void pop()
    {
    nod *p;
    //try{
    //    try{
    if(prim==NULL)return;
    //}
    //catch(nod* prim){
    //cout<<"nu am ce sa sterg"<<endl;
    //throw;
    //}
    if(ultim==NULL && prim!=NULL)
    {
        //cout<<"mai am doar prim"<<endl;
        delete prim;
        prim=NULL;
        return;
    }
    if(prim->getnext() == ultim)
    {
        char *c;
        c=ultim->getinfo();
        delete prim;
        delete ultim;
        ultim=NULL;
        prim=new nod(c);
        delete c;
        return;
    }
    //}
    /*catch(nod* prim){
        delete prim;
        prim=NULL;
    }*/
    /*catch(char* c){
        delete prim;
        delete ultim;
        ultim=NULL;
        prim=new nod(c);
        delete c;
        return;
    }*/
    p=prim;
    prim=prim->getnext();
    delete p;
    }
    void erasee()
    {
        if(prim==NULL){cout<<"nu am ce sa sterg"<<endl;return;}
        nod *p;
        while(prim)
        {
        p=prim;
        //cout<<"sterg "<<p->getinfo()<<endl;
        delete p;
        prim=prim->getnext();
        }
    }
    ~DEQUE(){
    erasee();
    }
    void addpoz(char* c,int poz)
    {
        /*nod *p,*o,*u;
        //try{
        if(!dimcheck())return;
        //}
        //catch(int dim_max){
        //cout<<"coada a depasit "<<dim_max<<" elemente; nu se mai pot adauga"<<endl;
       // }
        int i;
        if(poz<=1){coada::add(c);return;}
        for(p=prim,i=1;i<=poz && p!=NULL;p=p->getnext(),i++);
        if(p==NULL){
            u=new nod(c);
            u->urm(prim);
            prim=u;
            return;
        }
        for(o=prim;p!=NULL;p=p->getnext(),o=o->getnext());
        u=new nod(c);
        u->urm(o->getnext());
        o->urm(u);*/
        try{
        if(!dimcheck())throw dim_max;
        if(dimcheckplus(poz))throw dimcheckplus(poz);
        if(poz==1)throw c;
        throw 'a';
        }
        catch(const char ch){
        int i;
        nod *p,*o,*u;
        for(p=prim,i=1;i<=poz && p!=NULL;p=p->getnext(),i++);
        if(p==NULL){
            u=new nod(c);
            u->urm(prim);
            prim=u;
            return;
        }
        for(o=prim;p!=NULL;p=p->getnext(),o=o->getnext());
        u=new nod(c);
        u->urm(o->getnext());
        o->urm(u);
        return;
        }
        catch(char* c){
        coada::add(c);
        return;
        }
        catch(int dim_max){
        cout<<"coada a depasit "<<dim_max<<" elemente; nu se mai pot adauga"<<endl;
        return;
        }
        catch(bool bo){
        nod *p;
        p=new nod(c);
        p->urm(prim);
        prim=p;
        delete p;
        }
    }
};
int main(){
coada **a;
int n;
a=new coada*[10];
cout<<"Numar de obiecte; maxim 10:"<<endl<<endl;
cin>>n;
cout<<endl<<n<<" obiecte:"<<endl<<endl;
for(int i=0;i<=n;i++)
    {
        a[i]=new DEQUE(NULL,NULL);
        cin>>a[i];
    }
for(int i=1;i<=n;i++)
    {cout<<a[i]<<endl;
    //a[i]->erasee();
    delete a[i];
    }
delete a;
/*coada *b;
char comanda[10],c[10];
int nr;
b=new DEQUE(NULL,NULL);
cout<<"citire - adauga mai multe cuvinte, separate prin spatiu
cout<<"add - adauga cuvantul la finalul cozii"<<endl;
cout<<"insert <cuvant> <prioritate> - adauga cuvantul in coada cu prioritatea respectiva"<<endl;
cout<<"top - intoarce primul cuvant din coada(prioritate maxima)"<<endl;
cout<<"pop - elimina primul element din coada"<<endl;
cout<<"empty - goleste coada"<<endl;
cout<<"end - termina programul"<<endl;
while(1){
    cin>>comanda;
    if(!strcmp(comanda,"insert")){
            cin>>c;
            cin>>nr;
            b->addpoz(c,nr);
            //delete c;
    }
    if(!strcmp(comanda,"add")){
            if(b->dimcheck()){
            cin>>c;
            b->add(c);
            //delete c;
            }
    }
    if(!strcmp(comanda,"erase")){
        b->erasee();
    }
    if(!strcmp(comanda,"top"))cout<<b->top()<<endl;
    if(!strcmp(comanda,"pop"))b->pop();
    if(!strcmp(comanda,"afis"))cout<<b<<endl;
    if(!strcmp(comanda,"end"))return 0;
}*/
return 0;
}

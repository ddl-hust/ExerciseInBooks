#include<string>
#include<iostream>
using std::string;
using std::cout;
class Quote
{
private:
    string bookid;

protected:
     double price;

public:
    Quote(/* args */)=default;
    Quote(const string& s,double p):bookid(s),price(p){}
    virtual ~Quote()=default;
    string isbn(){return bookid;}
    virtual double net_price(size_t n) const{
        return price*n;
    }
    virtual void debug(){
        cout<<bookid<<" "<<price<<std::endl;
    }
};
//纯虚类
class disc_quote:public  Quote{
public:
    disc_quote()= default;
    disc_quote(const string& s,double p,double n,double q):Quote(s,p),mini_number(n),quote(q){}
    double net_price(size_t n) const =0; //base net_price() 已经定义了，这里Pure ok?

protected:
    double mini_number;
    double quote;
};
class Bulk_QUote:public disc_quote{
    public:
    Bulk_QUote()=default;
    Bulk_QUote(const string& s,double p,double n,double q):disc_quote(s,p,n,q){}
    double net_price(size_t n) const override{
        if(n>mini_number) return price*(1-quote)*n;
        else return price*n;
    }
    void debug() override{
        Quote::debug();
        cout<<mini_number<<" "<<quote<<std::endl;
    }
    private:

};

#include"iostream"

class baseClass{
    public:
        baseClass(int x,int y){x=x;y=y;}
    private:
        int x;
    protected:
        int y;    
};

int main(){
    baseClass obj(3,4);
    // obj.y =7;
    return 0;
}
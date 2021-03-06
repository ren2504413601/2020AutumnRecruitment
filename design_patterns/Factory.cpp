/**
 * 工厂模式包括：简单工厂模式、工厂方法模式、抽象方法模式
 * 工厂模式的主要作用是封装对象的创建，分离对象的创建和操作过程，
 * 用于批量管理对象的创建过程，便于程序的维护和扩展
 * https://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/simple_factory.html
 * https://github.com/me115/design_patterns
*/

#include<bits/stdc++.h>
using namespace std;

// 简单工厂模式
// 简单工厂模式是工厂模式最简单的一种实现，对于不同产品的创建定义一个工厂类，
// 将产品的类型作为参数传入到工厂的创建函数，根据类型分支选择不同的产品构造函数

#define simpleFactory
#ifdef simpleFactory

typedef enum ProductTypeTag
{
    TypeA,
    TypeB,
    TypeC
}PRODUCTTYPE;

class Product//产品抽象基类
{
public:
    virtual void Show() = 0;
};

class ProductA : public Product
{
public:
    void Show()
    {
        cout<<"I'm ProductA"<<endl;
    }
};
class ProductB : public Product
{
public:
    void Show()
    {
        cout<<"I'm ProductB"<<endl;
    }
};
class ProductC : public Product
{
public:
    void Show()
    {
        cout<<"I'm ProductC"<<endl;
    }
};
class Factory//工厂类
{
public:
    Product* CreateProduct(PRODUCTTYPE type)
    {
        switch (type)
        {
            case TypeA:
            return new ProductA();
            case TypeB:
            return new ProductB();
            case TypeC:
            return new ProductC();
            default:
            return NULL;
        }
    }
};
int main()
{
    Factory productCreator;
    Product *productA=productCreator.CreateProduct(TypeA);
    Product *productB=productCreator.CreateProduct(TypeB);
    Product *productC=productCreator.CreateProduct(TypeC);
    productA->Show();
    productB->Show();
    productC->Show();
    if(productA)
    {
        delete productA;
        productA=NULL;
    }
    if(productB)
    {
        delete productB;
        productB=NULL;
    }
    if(productC)
    {
        delete productC;
        productC=NULL;
    }
    system("pause");
    return 0;
}
#endif


// 工厂方法模式
// 简单工厂模式只是一个简单的对创建过程封装。工厂方法模式在简单工厂模式的基础上增加对工厂的基类抽象，
// 不同的产品创建采用不同的工厂创建（从工厂的抽象类派生），这样创建不同产品的过程就由不同的工厂分工解决：
// FactoryA专心负责生产ProductA，FactoryB专心负责生产ProductB，FactoryA和FactoryB之间没有关系；如果到了后期，
// 如果需要生产ProductC时，我们则可以创建一个FactoryC工厂类，该类专心负责生产ProductC类产品。
// 该模式相对于简单工厂模式的优势在于：便于后期产品种类的扩展

// #define FactoryMethod
#ifdef FactoryMethod
typedef enum ProductTypeTag
{
    TypeA,
    TypeB,
    TypeC
}PRODUCTTYPE;

class Product//产品抽象基类
{
public:
    virtual void Show() = 0;
};

class ProductA : public Product
{
public:
    void Show()
    {
        cout<<"I'm ProductA"<<endl;
    }
};
class ProductB : public Product
{
public:
    void Show()
    {
        cout<<"I'm ProductB"<<endl;
    }
};
class ProductC : public Product
{
public:
    void Show()
    {
        cout<<"I'm ProductC"<<endl;
    }
};
class Factory//工厂类
{
public:
    virtual Product* CreateProduct() = 0;
};


class FactoryA : public Factory
{
public:
    Product* CreateProduct() {return new ProductA();}
};

class FactoryB : public Factory
{
public:
    Product* CreateProduct() {return new ProductB();}
};



int main()
{
    Factory* factoryA = new FactoryA();
    Product* productA= factoryA->CreateProduct();
    productA->Show();

    Factory* factoryB = new FactoryB();
    Product* productB= factoryB->CreateProduct();
    productB->Show();

    

    if (factoryA) {delete factoryA; factoryA = NULL;}
    if (factoryB) {delete factoryB; factoryB = NULL;}
    if (productA) {delete productA; productA = NULL;}
    if (productB) {delete productB; productB = NULL;}
  
    system("pause");
    return 0;
}
#endif


// 抽象工厂模式
// 抽象工厂模式对于工厂模式进行了更加一般化的描述。工厂方法模式适用于产品种类结构单一的场合，
// 为一类产品提供创建的接口；而抽象工厂方法适用于产品种类结构多的场合，就是当具有多个抽象产品
// 类型时，抽象工厂就比较适用
// 抽象工厂模式更适合实际情况，受生产线所限，
// 让低端工厂生产不同种类的低端产品，高端工厂生产不同种类的高端产品。


// #define AbastractFactory
#ifdef AbastractFactory

class ProductA
{
public:
    virtual void Show() = 0;
};
class ProductA1 : public ProductA//A类低端产品
{
public:
    void Show()
    {
        cout<<"I'm ProductA1"<<endl;
    }
};
class ProductA2 : public ProductA//A类高端产品
{
public:
    void Show()
    {
        cout<<"I'm ProductA2"<<endl;
    }
};

class ProductB
{
public:
    virtual void Show() = 0;
};
class ProductB1 : public ProductB//B类低端产品
{
public:
    void Show()
    {
        cout<<"I'm ProductB1"<<endl;
    }
};
class ProductB2 : public ProductB//B类高端产品
{
public:
    void Show()
    {
        cout<<"I'm ProductB2"<<endl;
    }
};
class Factory
{
public:
    virtual ProductA *CreateProductA() = 0;
    virtual ProductB *CreateProductB() = 0;
};
class Factory1 : public Factory//1号工厂用于生产低端产品
{
public:
    ProductA *CreateProductA()
    {
        return new ProductA1();
    }
    ProductB *CreateProductB()
    {
        return new ProductB1();
    }
};
class Factory2 : public Factory//2号工厂用于生产高端产品
{
    ProductA *CreateProductA()
    {
        return new ProductA2();
    }
    ProductB *CreateProductB()
    {
        return new ProductB2();
    }
};
int main()
{
    Factory *factory1 = new Factory1();
    ProductA *productA1 = factory1->CreateProductA();
    ProductB *productB1 = factory1->CreateProductB();
    productA1->Show();
    productB1->Show();
    Factory *factory2 = new Factory2();
    ProductA *productA2 = factory2->CreateProductA();
    ProductB *productB2 = factory2->CreateProductB();
    productA2->Show();
    productB2->Show();
    if (factory1) {delete factory1; factory1 = NULL;}
    if (productA1) {delete productA1; productA1= NULL;}
    if (productB1)
    {
        delete productB1;
        productB1 = NULL;
    }
    if (factory2)
    {
        delete factory2;
        factory2 = NULL;
    }
    if (productA2)
    {
        delete productA2;
        productA2 = NULL;
    }
    if (productB2)
    {
        delete productB2;
        productB2 = NULL;
    }
    system("pause");
    return 0;
}
#endif
#include <QCoreApplication>
#include <Counter.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Counter a(1);
    Counter b(2);

    std::cout << "Default values: " << std::endl;
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
    std::cout << std::endl;

    QObject::connect(&a, &Counter::Signal, &b, &Counter::Slot);
    QObject::connect(&b, &Counter::Signal, &a, &Counter::Slot);

    std::cout << "Increment a: " << std::endl;
    a.Increment();
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
    std::cout << std::endl;

    std::cout << "Increment b: " << std::endl;
    b.Increment();
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
    std::cout << std::endl;

    std::cout << "Decrement a: " << std::endl;
    a.Decrement();
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
    std::cout << std::endl;

    std::cout << "Decrement b: " << std::endl;
    b.Decrement();
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;

    return app.exec();
}

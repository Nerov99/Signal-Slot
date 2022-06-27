#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <iostream>

class Counter: public QObject {
    Q_OBJECT
private:
    int m_count;
public:
    Counter(int startValue): m_count{startValue} {}
    int Increment() {
        ++m_count;
        emit Signal(true);
        return m_count;
    }
    int Decrement() {
        --m_count;
        emit Signal(false);
        return m_count;
    }
    int getValue() {
        return m_count;
    }

public slots:
    void Slot(bool state) {
        if(state)
            ++m_count;
        else
            --m_count;

        std::cout << "m_count was changed through emitting signal IncrementSignal" << std::endl;
    }
signals:
    void Signal(bool state);
};

#endif // COUNTER_H

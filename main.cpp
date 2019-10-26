#include <QCoreApplication>
#include <QDebug>
#include <QList>

unsigned int get_max(QList <int> list, unsigned int length){
    int max_number = 0;
    unsigned int max_number_index = 0;

    for(unsigned int i = 0; i < length;i++){
        if (max_number < list.value(i)) {
            max_number = list.value(i);
            max_number_index = i;
        }
    }

    return max_number_index;
}

void sort_list(QList <int> &list){
    unsigned int length = static_cast<unsigned int> (list.length());

    for(unsigned int i = 0; i < length;i++){
        unsigned int index = get_max(list, length - i);

        list.swap(index, length - i - 1);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList <int> list;

    list.push_back(5);
    list.push_back(15);
    list.push_back(4);
    list.push_back(8);
    list.push_back(9);
    list.push_back(7);
    list.push_back(16);
    list.push_back(12);
    list.push_back(24);

    //qDebug() << get_max(list, static_cast<unsigned int> (list.length()));
    sort_list(list);

    for(unsigned int i = 0; i < static_cast<unsigned int> (list.length());i++){
        qDebug() << list.value(i);
    }

    return a.exec();
}

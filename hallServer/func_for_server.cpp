#include "func_for_server.h"
#include <QCoreApplication>
#include <QDebug>
#include <algorithm>
using namespace std;

QByteArray parsing(QString str)
{
    QStringList params;
    params.clear();
    params = str.split("&");
    QString func_name;
    func_name.clear();
    func_name = params.front();

    //params.pop_front(); sort step 1 2 3 4 5 6

    QString input_array = params[2];
    QStringList params1 = input_array.split(" ");


    if(func_name=="sort")
        return sort(params1, params[1]);
    else
        return "Error";
}

void heapify(QList<int> arr, int i, int m) {
    int j = i;
    int k = i*2+1;
    while (k<=m){
        if(k<m && arr[k] < arr[k+1])
        {k++;};
        if(arr[j] < arr[k]){
            swap(arr[j],arr[k]);
            j=k;
            k = k*2+1;
        }
        else{
            break;
        }

    }

}


QByteArray sort(QStringList arr, QString step) {
    QList<int> arr1;
    for (int i = 0; i < arr.size(); i++) {
        arr1.append(arr[i].toInt());
    }

    int counter = 0;
    int n = arr1.size();
    for (int i = n / 2; i >= 0; i--)
        heapify(arr1, i , n-1);

    while (counter != step.toInt()) {
        for (int m = n - 1; m >= 1; m--) {
            swap(arr1[0], arr1[m]);
            heapify(arr1, 0, m - 1);
        }
        counter++;
    }

    QByteArray step1 = QString::number(counter).toUtf8();
    return step1;

}

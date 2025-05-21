#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

string verschluesseln(string eingabe, int schluessel);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    string s;
    int schluessel;
    cout << "Bitte geben Sie ihren zu verschlüsselnden Text ein:" << endl;
    getline(cin,s);
    cout << "Bitte geben Sie ihren Schlüseel ein" << endl;
    cin >> schluessel;
    string cypher = verschluesseln(s,schluessel);
    cout << cypher << endl;
    return a.exec();
}
// 99 - 97 = 2 + 3 = 5 --> 5 + 97 = 102
string verschluesseln(string eingabe, int schluessel){
    string cypher = "";

    for(int i = 0; i < eingabe.size(); i++){
        if (schluessel >= 0){
            char c = eingabe[i];
            if (c >= 'a' && c <= 'z'){
                c = (c - 'a' + schluessel) % 26 + 'a';
            }
            cypher += c;
        }
        if (schluessel < 0){
            char c = eingabe[i];
            if (c >= 'a' && c <= 'z'){
                c = (c - 'a' + schluessel + 26) % 26 + 'a';
            }
            cypher += c;
        }
    }
    return cypher;
}

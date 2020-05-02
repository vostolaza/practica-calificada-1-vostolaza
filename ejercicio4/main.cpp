#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> stringToVector(string &s){
    stringstream ss(s);
    vector<int> v;
    int value;
    while(ss >> value)
        v.push_back(value);
    return v;
}



int main() {

    // Generamos el vector con indices
    string row1;
    getline(cin, row1);
    vector<int> vPosition = stringToVector(row1);

    // Obtenemos n para saber la cantidad de inputs
    int n = vPosition.size();

    // Generamos vector con numeros reales a insertar en el vector final
    float aux;
    vector<float> numSet;
    for (int i = 0; i < n; i++){
        cin >> aux;
        numSet.push_back(aux);
    }

    // Obtenemos la distancia entre numeros
    int d; cin >> d;

    // Obtenemos el valor filler
    int f; cin >> f;

    // Generamos el vector de respuesta con el valor filler. EL tamaño del vector es igual a [n + (n-1)*d] ya que
    // se tienen n valores separados por d-1 fillers, pero al ultimo valor no le sigue filler.
    vector<int> result(n+(n-1)*(d-1), f);

    for (int i = 0; i < n; i++){
        // Se inserta cada valor en el indice indicado -1 ya que el vector comienza en 0, multiplicado por d que son los
        // fillers de por medio.
        int position = (vPosition[i]-1)*d;
        result[position] = numSet[i];
    }

    for (const auto &i: result)
        cout << i << " ";

    return 0;
}

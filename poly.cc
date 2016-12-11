#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include <fstream>
#include <sstream>


using namespace std;

class Poly {
    public:
        int order;
        vector<long long> values;
    

};


Poly add_poly(Poly one, Poly two) {
    Poly newPoly;
    int max;
    if(one.order > two.order) {

        newPoly.order = one.order;
        max = one.values.size();
        for(int j = 0; j < one.order - two.order; j++) {
            two.values.insert(two.values.begin(), 0);
        }
    }
    else if(two.order > one.order) {

        newPoly.order = two.order;
        max = two.values.size();
        for(int j = 0; j < two.order - one.order; j++) {
            one.values.insert(one.values.begin(), 0);
        }
    }
    else {

        max = one.values.size();
        newPoly.order = one.order;
    }

    for(int k = 0; k < max; k++) {
        newPoly.values.push_back(one.values.at(k) + two.values.at(k));

    }

    return newPoly;
}




vector<long long> fileRead(string file_name){
    string temp;
    long long temp2;

    vector<long long> numbers;

    stringstream ssin(file_name);

    while(ssin.good()){
        ssin >> temp;
        stringstream convert(temp);
        convert >> temp2;
        numbers.push_back(temp2);
    }

    return numbers;
}

string fileIn(string fileName) {
    string text,line;
    ifstream file;
    file.open(fileName.c_str());
     if (file.is_open())
  {
    while ( getline (file,line) )
    {
      text = text + line + " ";
    }
    file.close();
  }
  else cout << "Unable to open file" << endl;
    file.close();


    return text;
}

int main(int argc, char* argv[]) {
    vector<long long> tmp = fileRead(fileIn(argv[1]));
    Poly poly1, poly2;

    poly1.order = tmp.at(0);
    //cout << poly1.order << " ";
    for(int j = 1; j < tmp.size()-1; j++) {
        poly1.values.push_back(tmp.at(j));
       // cout << poly1.values.at(j-1) << " ";
    }
    //cout << endl;

    tmp = fileRead(fileIn(argv[2]));
    poly2.order = tmp.at(0);
    //cout << poly2.order << " ";
    for(int j = 1; j < tmp.size()-1; j++) {
        poly2.values.push_back(tmp.at(j));
       // cout << poly2.values.at(j-1) << " ";
    }
    //cout << endl;

    //Poly output = add_poly(poly1, poly2);
   Poly output = add_poly(poly1, poly2);
    // cout << output.values.empty(); //1
    //cout << poly1.values.empty(); //0
    //cout << poly2.values.empty(); //0
    cout << output.order << " ";
    for(int j = 0; j < output.values.size(); j++) {
        cout << output.values.at(j) << " ";
    }
    cout << endl;
    
    return 0;
}

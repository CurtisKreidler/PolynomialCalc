#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;

class Poly {
    public:
        int order;
        vector<int> values;
        /*
        Poly(vector<int> numbers) {
            order = numbers.at(0);
            for(int j = 1; j < numbers.size(); j++) {
                values.push_back(numbers.at(j));
            }
        }
        */

};

Poly multi_poly(Poly one, Poly two){// Multiplies two polynomials
    
    Poly newPoly;
    vector<int>::iterator poly_iterator1, poly_iterator2;

    for(poly_iterator1 = one.values.begin();
     poly_iterator1 != one.values.end(); poly_iterator1++){
        
        if(*poly_iterator1 != 0 ){
            
            for(poly_iterator2 = two.values.begin();
             poly_iterator2 != two.values.end(); poly_iterator2++){

            if(*poly_iterator2 != 0 ){ 
            
             newPoly.values.push_back(*poly_iterator1 * *poly_iterator2);
                
            }//if
        
                 
            }//poly_iterator2 for end
            
        }//if 
   
    }//poly_iterator1 for end
   
    newPoly.values.insert(newPoly.values.begin(), newPoly.values.size() + 1);
    
  return newPoly;
}


Poly add_poly(Poly one, Poly two) {
    Poly newPoly;
    int max;
    if(one.order > two.order) {

        newPoly.order = one.order;
        max = one.values.size();
        for(int j = 0; j < one.order - two.order; j++) {
            two.values.emplace(two.values.begin(), 0);
        }
    }
    else if(two.order > one.order) {

        newPoly.order = two.order;
        max = two.values.size();
        for(int j = 0; j < two.order - one.order; j++) {
            one.values.emplace(one.values.begin(), 0);
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




vector<int> fileRead(string file_name){
    string temp;
    //Poly newPoly;
    int temp2;

    vector<int> numbers;

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
    file.open(fileName);
     if (file.is_open())
  {
    while ( getline (file,line) )
    {
      text = text + line + " ";
      //cout << text << endl;
    }
    file.close();
  }
  else cout << "Unable to open file" << endl;
    file.close();


    return text;
}

int main(int argc, char* argv[]) {
   /*
    Poly *poly1 = new Poly(fileRead(fileIn(argv[1])));
    Poly *poly2 = new Poly(fileRead(fileIn(argv[2])));
    Poly output = add_poly(*poly1, *poly2);
    */
    vector<int> tmp = fileRead(fileIn(argv[1]));
    Poly poly1, poly2;

    poly1.order = tmp.at(0);
    cout << poly1.order << " ";
    for(int j = 1; j < tmp.size()-1; j++) {
        poly1.values.push_back(tmp.at(j));
        cout << poly1.values.at(j-1) << " ";
    }
    cout << endl;

    tmp = fileRead(fileIn(argv[2]));
    poly2.order = tmp.at(0);
    cout << poly2.order << " ";
    for(int j = 1; j < tmp.size()-1; j++) {
        poly2.values.push_back(tmp.at(j));
        cout << poly2.values.at(j-1) << " ";
    }
    cout << endl;

    Poly pls = multi_poly(poly1,poly2);
    
    for(int z = 0; z < pls.values.size(); z++){
        cout << pls.values.at(z) << " ";
    }
    
    //Poly output = add_poly(poly1, poly2);
  //  Poly output = add_poly(poly1, poly2);
    // cout << output.values.empty(); //1
    //cout << poly1.values.empty(); //0
    //cout << poly2.values.empty(); //0
    // cout << output.order << " ";
    // for(int j = 0; j < output.values.size(); j++) {
    //     cout << output.values.at(j) << " ";
    // }
    // cout << endl;

    return 0;
}

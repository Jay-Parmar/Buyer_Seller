#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
// If time, add word prediction to the buyers seeking products or services
// Functions to enable buyers and sellers to view their products or services

bool checkSeller(string name){
    ifstream fp;
    fp.open("sellerlist.txt", ios::in);
    string getname;
    while (getline(fp, getname)){
        if (getname == name){
            return true;
        }
    }
    fp.close();
    return false;
}

bool checkBuyer(string name){
    ifstream fp;
    fp.open("buyerlist.txt", ios::in);
    string getname;
    while (getline(fp, getname)){
        if (getname == name){
            return true;
        }
    }
    fp.close();
    return false;
}

void regSeller(string name){

    if (checkSeller(name)){
        cout<< "You are already Registered."<<endl;
        return;
    }
    ofstream fp;
    fp.open("sellerlist.txt", ios::out | ios::app);
    fp << name << endl;
    fp.close();
}

void regBuyer(string name){
    if (checkBuyer(name)){
        cout<< "You are already Registered."<<endl;
        return;
    }
    ofstream fp;
    fp.open("buyerlist.txt", ios::out | ios::app);
    fp << name << endl;
    fp.close();
}

void addSeller(string name){

    if (!checkSeller(name)){
        cout<< "You are not previously Registered. Register again."<<endl;
        return;
    }
    int ad = 0;
    while (ad < 3){

        cout << "\n\n\n\n\n\n"<<endl;
        cout << "-----------------------------------------------------------------------------\n\n\n"<<endl;
        cout << " What You Want to Add :: "<<endl;
        cout << " 1. Product"<<endl;
        cout << " 2. Service"<<endl;
        cout << " 3. Exit to Category Window"<<endl;
        cin>>ad;
        if (ad == 1){
            ofstream fp;
            fp.open("products.txt", ios::out | ios::app);
            string prod;
            int price;
            cout << "Enter name of Your Product : "<<endl;
            getline(cin, prod);
            getline(cin, prod);
            cout << "Enter Price of This Product : "<<endl;
            cin>>price;
            fp<<prod<<"-$"<<price<<"$="<<name<<"="<<endl;
            fp.close();
        }else if (ad == 2){
            ofstream fp;
            fp.open("services.txt", ios::out | ios::app);
            string serv;
            int price;
            cout << "Enter name of Your Service : "<<endl;
            getline(cin, serv);
            getline(cin, serv);
            cout << "Enter Price of This Service : "<<endl;
            cin>>price;
            fp<<serv<<"-$"<<price<<"$="<<name<<"="<<endl;
            fp.close();
        }
    }

}

void addBuyer(string name){
    if (!checkBuyer(name)){
        cout << "\n\n\n\n\n\n"<<endl;
        cout << "----------------------------------------------------------------------------------\n\n\n"<<endl;
        cout<< "You are not previously Registered. Register again."<<endl;
        return;
    }
    int ad = 0, val = 0;
    vector<string> ordered;
    while (ad < 5){
        cout << "\n\n\n\n\n\n"<<endl;
        cout << "------------------------------------------------------------------------------\n\n\n"<<endl;
        cout << "            What You Want to Add :: "<<endl;
        cout << "            1. Product"<<endl;
        cout << "            2. Service"<<endl;
        cout << "            3. Total value of Your Orders Placed"<<endl;
        cout << "            4. List of Your Items Ordered"<<endl;
        cout << "            5. Exit to Category Window"<<endl;
        cin>>ad;
        if (ad == 1){
            ifstream fp;
            fp.open("products.txt");
            string prod,str,T;
            cout << "Enter name of Your Product : "<<endl;
            getline(cin, prod);
            getline(cin, prod);
            vector<string> v;

            while (getline(fp, str)){
                stringstream X(str);
                getline (X,T,'-');
                if (T==prod){
                    v.push_back(str);
                }
            }
            if (v.size() == 1){
                stringstream X(v[0]);
                getline(X,T,'$');
                getline(X,T,'$');
                stringstream geek (T);
                int x=0;
                geek>>x;
                val += x;
                string T1;
                //stringstream Y(v[0]);
                getline(X,T1,'-');
                ordered.push_back(T1+" "+T);

            }else if (v.empty()){
                cout << "No Products Found"<<endl;
            }else{
                int temp;
                cout << "Multiple Products found from different Sellers : "<<endl;
                for(int i=0; i<v.size(); i++){
                    cout<< i+1 <<". "<< v[i] << endl;
                }
                cout << "Enter Your Choice : ";
                cin>>temp;
                if (temp > v.size()){
                    cout << "Invalid Input"<<endl;
                    break;
                }
                stringstream X(v[temp-1]);
                getline(X,T,'$');
                getline(X,T,'$');
                stringstream geek (T);
                int x=0;
                geek>>x;
                val += x;
                string T1;
                getline(X,T1,'-');
                ordered.push_back(T1+" "+T);

            }


            fp.close();
        }else if (ad == 2){
            ifstream fp;
            fp.open("services.txt", ios::in);
            string serv,str,T;
            cout << "Enter name of Your Service : "<<endl;
            getline(cin, serv);
            getline(cin, serv);

            vector<string> v;
            while (getline(fp, str)){
                stringstream X(str);
                getline (X,T,'-');
                if (T==serv){
                    v.push_back(str);
                }
            }
            if (v.size() == 1){
                stringstream X(v[0]);
                getline(X,T,'$');
                getline(X,T,'$');
                stringstream geek (T);
                int x=0;
                geek>>x;
                val += x;
                string T1;
                getline(X,T1,'-');
                ordered.push_back(T1+" "+T);
            }else if (v.empty()){
                cout << "No Services Found"<<endl;
            }else{
                int temp;
                cout << "Multiple Services found from different Sellers : "<<endl;
                for(int i=0; i<v.size(); i++){
                    cout<< i+1 <<". "<< v[i] << endl;
                }
                cout << "Enter Your Choice : ";
                cin>>temp;
                if (temp > v.size()){
                    cout << "Invalid Input"<<endl;
                    break;
                }
                stringstream X(v[temp-1]);
                getline(X,T,'$');
                getline(X,T,'$');
                stringstream geek (T);
                int x=0;
                geek>>x;
                val += x;
                string T1;
                getline(X,T1,'-');
                ordered.push_back(T1+" "+T);

            }
            fp.close();
        }else if (ad == 3){
            cout << "Total Value of Your Order Till Now is : "<<val<<endl;
        }else if (ad == 4){
            for (int i=0; i<ordered.size(); i++){
                cout << ordered[i] << endl;
            }
        }
    }
}

void delSeller(string name){
    if (!checkSeller(name)){
        cout<< "You are not previously Registered. Register again."<<endl;
        return;
    }
    int ad = 0;
    while (ad < 3){
        cout << "\n\n\n\n\n\n"<<endl;
        cout << "-----------------------------------------------------------------------------------------\n\n\n"<<endl;
        cout << " What You Want to Delete :: "<<endl;
        cout << " 1. Product"<<endl;
        cout << " 2. Service"<<endl;
        cout << " 3. Exit to Category Window"<<endl;
        cin>>ad;
        if (ad == 1){
            ifstream fp;
            ofstream fp1;
            string str, T;
            fp.open("products.txt");
            fp1.open("products1.txt");
            string prod;
            cout << "Enter name of Your Product : "<<endl;
            getline(cin, prod);
            getline(cin, prod);
            while (getline(fp, str)){
                stringstream X(str);
                getline (X,T,'-');
                if (T==prod){
                    continue;
                }
                fp1<<str<<endl;
            }
            fp1.close();
            fp.close();
            remove("products.txt");
            rename("products1.txt", "products.txt");

        }else if (ad == 2){
            ifstream fp;
            ofstream fp1;
            string str, T;
            fp.open("services.txt");
            fp1.open("services1.txt");
            string serv;
            cout << "Enter name of Your Service : "<<endl;
            getline(cin, serv);
            getline(cin, serv);
            while (getline(fp, str)){
                stringstream X(str);
                getline (X,T,'-');
                if (T==serv){
                    continue;
                }
                fp1<<str<<endl;
            }
            fp1.close();
            fp.close();
            remove("services.txt");
            rename("services1.txt", "services.txt");

        }
    }
}

int main(){
    int n, s=0, b=0;
    while (true){
        cout << "\n\n\n\n\n\n"<<endl;
        cout << "--------------------------------------------------------------------------------------------\n\n\n"<<endl;
        cout << "                       :: Enter Your Category From Below :: "<<endl;
        cout << "                       1. Seller"<<endl;
        cout << "                       2. Buyer"<<endl;
        cout << "                       3. None. Exit"<<endl;
        cin>>n;
        if (n==1){
            string name;
            cout << "\n            Enter Your Company's Name : "<<endl;
            getline(cin, name);
            getline(cin, name);
            while (s <6 && s>=0){
                cout << "\n\n\n\n\n\n\n"<<endl;
                cout << "--------------------------------------------------------------------------------------------\n\n\n"<<endl;
                cout << "                      :: Enter Your Purpose ::"<<endl;
                cout << "                      1. Register Yourself "<<endl;
                cout << "                      2. Add New Products"<<endl;
                cout << "                      3. Delete Old Products"<<endl;
                cout << "                      4. Exit to category Window"<<endl;
                cout << "                      5. Exit totally"<<endl;
                cin>>s;
                if (s==1){
                    regSeller(name);
                }else if (s==2){
                    addSeller(name);
                }else if (s==3){
                    delSeller(name);
                }else if (s==4){
                    break;
                }else{
                    return 0;
                }

            }
        }else if (n==2){
            string name;
            cout << "\n            Enter Your User Id : "<<endl;
            getline(cin, name);
            getline(cin, name);
            while (b>=0 && b<5){
                cout << "\n\n----------------------------------------------------------------------------------------\n\n\n"<<endl;
                cout << "                      :: Enter Your Purpose ::"<<endl;
                cout << "                      1. Register Yourself "<<endl;
                cout << "                      2. Add Products or Services"<<endl;
                cout << "                      3. Exit to category Window"<<endl;
                cout << "                      4. Exit Totally"<<endl;
                cin>>b;
                if (b==1){
                    regBuyer(name);
                }else if (b==2){
                    addBuyer(name);
                }else if (b==3){
                    break;
                }else{
                    return 0;
                }
            }
        }else{
            return 0;
        }
        cout << "\n\n---------------------------------------------------------------------------------------\n\n\n"<<endl;
        cout << "                      :: Request Completed :: "<<endl;
        cout << "                      Enter any key to Go To Category Window"<<endl;
        cout << "                      Enter 0 to Exit"<<endl;
        cin>>n;
        if (n == 0){
            break;
        }
    }
}

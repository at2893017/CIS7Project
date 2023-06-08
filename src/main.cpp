/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * 
 * Final Project
 * Case 2: UCR Medical Volunteers 
 * Static Solution -> All physician information is predetermined, directly 
 * assigned within the program
 */

#include <iostream>
#include <cstdlib>
#include <valarray>
using namespace std;

struct COUNTRY {
    int lang; //language
              // Arabic(0), French(1), Bengali(2), Spanish(3), Russian(4)
    int nd; //number of doctors
    int spec[5]; 
};

void allp(int,int, float);

int main(int argc, char** argv) {
    COUNTRY clist[10] = { {0,9,{1,2,1,2,3}}, /*Lebanon*/
                          {0,12,{2,3,2,3,2}},/*Sudan*/  
                          {1,8,{1,1,2,1,3}}, /*Belgium*/  
                          {1,11,{3,2,1,2,3}},/*Burkina Faso*/  
                          {2,15,{1,4,4,2,4}},/*Bangladesh*/  
                          {3,13,{3,1,3,3,3}},/*Argentina*/  
                          {3,8,{1,2,2,1,1}}, /*Honduras*/  
                          {3,8,{0,4,1,2,1}}, /*Mexico*/  
                          {4,13,{1,5,2,4,1}},/*Ukraine*/  
                          {4,3,{1,0,0,1,1}} }; /*Russian Federation*/
    
    //variables input from user
    int ulang=0;     //user language
                   // Arabic(0), French(1), Bengali(2), Spanish(3), Russian(4)
    int uspec=0;     //user medical specialty
                   //Cardiology(0),Emergency Medicine(1), Infectious Disease(2),
                   //Marternal-Fetal Medicine(3), Medical  Oncology(4)
    
    //variables for calculation
    float plang[10]; //probability of matching with doctor of same language fluency
    float pspec[10]; //probability of matching with doctor of same specialization
    float pab[10]; //probability of selection given language and specialization
    int maxind=0;
    float maxval=0.0f;
    
    //Prompt User for language frequency and specialization
    cout<<"Select your language of fluency!\n"
            <<"Arabic(0), French(1), Bengali(2), Spanish(3), Russian(4): ";
    cin>>ulang;
    ulang=(ulang<0)?0:(ulang>4)?4:ulang;
    cout<<endl;
    
    cout<<"Select your medical specialization!\n"
            <<"Cardiology(0),Emergency Medicine(1), Infectious Disease(2),\n"
            <<"Marternal-Fetal Medicine(3), Medical  Oncology(4): ";
    cin>>uspec;
    uspec=(uspec<0)?0:(uspec>4)?4:uspec;
    cout<<endl;
    //Find plang 
    //100% in country that speaks language, 0% in country that doesn't speak language
    for(int i=0;i<10;i++) {
        if(ulang == clist[i].lang) {
            plang[i]=1.0f;
        }else{
            plang[i]=0.0f;
        }
    }
    
    //Find pspec
    // Found by dividing number of doctors in specialization over number of doctors
    // in country participating in program
    for(int i=0;i<10;i++){
        pspec[i]=clist[i].spec[uspec]/static_cast<float>(clist[i].nd);
    }
    
    //Find pab
    for(int i=0;i<10;i++){
        pab[i]=plang[i]*pspec[i];
    }
    
    //Print Probability
    cout<<"Probability of Finding Match in Country"<<endl;
    for(int i=0;i<10;i++) {
        switch(i) {
            case 0: cout<<"Lebanon: ";break;
            case 1: cout<<"Sudan: ";break;
            case 2: cout<<"Belgium: ";break;
            case 3: cout<<"Burkina Faso: ";break;
            case 4: cout<<"Bangladesh: ";break;
            case 5: cout<<"Argentina: ";break;
            case 6: cout<<"Honduras: ";break;
            case 7: cout<<"Mexico: ";break;
            case 8: cout<<"Ukraine: ";break;
            default: cout<<"Russian Federation: ";break; 
        }
        cout<<pab[i]<<endl;
    }
    
    cout<<endl;
    
    //find max pab
    for(int i=0;i<10;i++){
        if(pab[i]>maxval) {
            maxval=pab[i];
            maxind=i;
        }
    }
    
    cout<<"Your Match: ";
    switch(maxind) {
            case 0: cout<<"Lebanon";break;
            case 1: cout<<"Sudan";break;
            case 2: cout<<"Belgium";break;
            case 3: cout<<"Burkina Faso";break;
            case 4: cout<<"Bangladesh";break;
            case 5: cout<<"Argentina";break;
            case 6: cout<<"Honduras";break;
            case 7: cout<<"Mexico";break;
            case 8: cout<<"Ukraine";break;
            default: cout<<"Russian Federation";break; 
    }
    return 0;
}


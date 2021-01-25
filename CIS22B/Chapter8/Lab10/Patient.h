/*
 Specification file for the Patient class
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>

using std:: string;


class Patient
{
    private:
        string name;
        int age;
        int weight;
        double height;
    
    public:
    // constructors
    Patient();
    Patient(string n, int a, double h, int w);
    
    // setters
    /* Write your code here */
    void setName(string n) {
        name = n;
    }
    
    void setWeight(int w) {
        weight = w;
    }
    
    void setHeight(int h) {
        height = h;
    }
    
    void setAge(int a) {
        age = a;
    }
    
    // getters
    
    string getName() {
        return name;
    }
    
    double getWeight() {
        return weight;
    }
    
    double getHeight() {
        return height;
    }
    
    int getAge() {
        return age;
    }
    
    /* operator overloads for < and << */
    bool operator < (const Patient &);
    friend std::ostream &operator << (std::ostream &, Patient &);
    
    // other functions: declare display and weightStatus
    /* Write your code here */
    void display() const;
    string weightStatus() const;
};

#endif

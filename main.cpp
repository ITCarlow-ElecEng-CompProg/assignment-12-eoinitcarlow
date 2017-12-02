/*Eoin Finlay
  Ex 12 Complex Num Calculation
  01 Dec 2017*/

//Preprocessor Directives
#include <iostream>
#include <cmath>

using namespace std;


//Structure Definitions
struct complexNum
{
   double real;
   double img;
};

struct polarnumber
{
    double mag, angle;
};

// Declaring Structure Functions
struct complexNum Add(struct complexNum, struct complexNum);
struct complexNum Sub(struct complexNum, struct complexNum);
struct complexNum Mul(struct complexNum, struct complexNum);
struct complexNum Div(struct complexNum, struct complexNum);

//Main Function
int main()
{
    //Declaring Function Members
    struct complexNum num1, num2;
    struct complexNum sum1, sum2, sum3, sum4;


    //Prompting User to enter values
    cout << "\n\nEnter a value for the first Real Number: ";
    cin >> num1.real;

    cout << "\nEnter a value for the first Imaginary Number: ";
    cin >> num1.img;

    cout << "\n\nEnter a value for the second Real Number: ";
    cin >> num2.real;

    cout << "\nEnter a value for the second Imaginary Number: ";
    cin >> num2.img;

    //assigning sum1 to Add Function
    sum1 = Add(num1, num2);

    if(sum1.img >=0)
        cout << "\n\nAdd = " << sum1.real << " + j" << sum1.img << endl;
    else
        cout << "\n\nAdd = " << sum1.real << " - j" << fabs(sum1.img) << endl;

    //assigning sum2 to Sub Function
    sum2 = Sub(num1, num2);

    if(sum2.img >=0)
        cout << "\n\nSub = " << sum2.real << " + j" << sum2.img << endl;
    else
        cout << "\n\nSub = " << sum2.real << " - j" << fabs(sum2.img) << endl;

    //assigning sum3 to Mul Function
    sum3 = Mul(num1, num2);

    if(sum3.img >=0)
        cout << "\n\nMul = " << sum3.real << " + j" << sum3.img << endl;
    else
        cout << "\n\nMul = " << sum3.real << " - j" << fabs(sum3.img) << endl;

    //assigning sum4 to Div Function
    sum4 = Div(num1, num2);

    if(sum3.img >=0)
        cout << "\n\nDiv = " << sum4.real << " + j" << sum4.img << endl;
    else
        cout << "\n\nDiv = " << sum4.real << " - j" << fabs(sum4.img) << endl;


    return 0;
}

//Add Function Header
struct complexNum Add(struct complexNum num1, struct complexNum num2)
{
  //declaring Function member
  struct complexNum res;

  //adding real with real and img with img and passing to result
  res.real = num1.real + num2.real;
  res.img = num1.img + num2.img;

return res;
}
//Sub Function Header
struct complexNum Sub(struct complexNum num1, struct complexNum num2)
{
  //declaring Function member
  struct complexNum res;

  //subtracting real with real and img with img and passing to result
  res.real = num1.real - num2.real;
  res.img = num1.img - num2.img;

  return res;
}

//Mul Function Header
struct complexNum Mul(struct complexNum num1, struct complexNum num2)
{
    //declaring members of to different structures
    struct complexNum res;
    struct polarnumber num1P, num2P, resP;

    //converting from cartesian to polar
    num1P.mag = sqrt(pow(num1.real, 2) + pow(num1.img, 2));
    num1P.angle = atan2(num1.img, num1.real);

    num2P.mag = sqrt(pow(num2.real, 2) + pow(num2.img, 2));
    num2P.angle = atan2(num2.img, num2.real);

    //multiplying in polar form
    resP.mag = num1P.mag * num2P.mag;
    resP.angle = num1P.angle + num2P.angle;

    //converting polar back to cartesian
    res.real = resP.mag * cos(resP.angle);
    res.img = resP.mag * sin(resP.angle);

    return res;
}

//Div Function Header
struct complexNum Div(struct complexNum num1, struct complexNum num2)
{
    //declaring members of to different structures
    struct complexNum res;
    struct polarnumber num1P, num2P, resP;

    //converting from cartesian to polar
    num1P.mag = sqrt(pow(num1.real, 2) + pow(num1.img, 2));
    num1P.angle = atan2(num1.img, num1.real);

    num2P.mag = sqrt(pow(num2.real, 2) + pow(num2.img, 2));
    num2P.angle = atan2(num2.img, num2.real);

    //dividing in polar form
    resP.mag = num1P.mag / num2P.mag;
    resP.angle = num1P.angle - num2P.angle;

    //converting polar back to cartesian
    res.real = resP.mag * cos(resP.angle);
    res.img = resP.mag * sin(resP.angle);


    return res;
}

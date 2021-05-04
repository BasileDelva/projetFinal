#include<string>
#include<cmath>
#include "fonctions.h"

using namespace std;

/*
  Les trois fonctions suivantes permettent de convertir un nombre decimal respectivement
  en : binaire, octal et hexadecimal
*/
//Cette fonction convertit un nombre decimal en binaire, elle renvoie un "string"
string decimal_to_binary(int number)
{
    string result = "";
    int reste;
    while (number != 0 && number != 1)
    {
        reste = number % 2;
        result = to_string(reste) + result;   
        number /= 2;
    }
    result = '1' + result;
    return result;
}

//Cette fonction convertit un nombre decimal en octal, elle renvoie un "string"
string decimal_to_octal(int number)
{
    string result = "";
    result = binary_to_octal(decimal_to_binary(number));
    return result;
}

//Cette fonction convertit un nombre decimal en hexadecimal, elle renvoie un "string"
string decimal_to_hexa(int number)
{
    string result = "";
    result = binary_to_hexa(decimal_to_binary(number));
    return result;
}


/*
  Les trois fonctions suivantes permettent de convertir un nombre binaire respectivement
  en : decimal, octal et hexadecimal
*/
//Cette fonction convertit un nombre binaire en decimal, elle renvoie un "int"
int binary_to_decimal(string number)
{
    int result = 0;
    for (int i = number.size() - 1; i >= 0; i--)
    {
        if (number[i] == '1')
            result += 1 * pow(2, number.size() - (i+1));  
    }
    return result;
}

//Cette fonction convertit un nombre binaire en octal, elle renvoie un "string"
string binary_to_octal(string number)
{
    string result = "", temp;

    int i = number.size() - 1, j;
    for(i; i>=0; i -= 3)
      {
        j = i;
        temp = "";
        while(j >= 0 && j >= i-2)
        {
            temp = number[j] + temp;
            j--;
        }
        if(temp == "000" || temp == "00" || temp == "0")
        result = '0' + result;
        else if(temp == "001" || temp == "01" || temp == "1")
        result = '1' + result;
        else if(temp == "010" || temp == "10")
        result = '2' + result;
        else if(temp == "011" || temp == "11")
        result = '3' + result;
        else if(temp == "100")
        result = '4' + result;
        else if(temp == "101")
        result = '5' + result;
        else if(temp == "110")
        result = '6' + result;
        else if(temp == "111")
        result = '7' + result;
      }
    result = format_number(result);
    return result;
}

//Cette fonction convertit un nombre binaire en hexadecimal, elle renvoie un "string"
string binary_to_hexa(string number)
{
  string result = "", temp;

  int i = number.size() - 1, j;
  for(i; i>=0; i -= 4)
    {
      j = i;
      temp = "";
      while(j >= 0 && j >= i-3)
      {
          temp = number[j] + temp;
          j--;
      }
      if(temp == "0000" || temp == "000" || temp == "00" || temp == "0")
      result = '0' + result;
      else if(temp == "0001" || temp == "001" || temp == "01" || temp == "1")
      result = '1' + result;
      else if(temp == "0010" || temp == "010" || temp == "10")
      result = '2' + result;
      else if(temp == "0011" || temp == "011" || temp == "11")
      result = '3' + result;
      else if(temp == "0100" || temp == "100")
      result = '4' + result;
      else if(temp == "0101" || temp == "101")
      result = '5' + result;
      else if(temp == "0110" || temp == "110")
      result = '6' + result;
      else if(temp == "0111" || temp == "111")
      result = '7' + result;
      else if(temp == "1000")
      result = '8' + result;
      else if(temp == "1001")
      result = '9' + result;
      else if(temp == "1010")
      result = 'A' + result;
      else if(temp == "1011")
      result = 'B' + result;
      else if(temp == "1100")
      result = 'C' + result;
      else if(temp == "1101")
      result = 'D' + result;
      else if(temp == "1110")
      result = 'E' + result;
      else if(temp == "1111")
      result = 'F' + result;
    }
  result = format_number(result);
  return result;
}

/*
  Les trois fonctions suivantes permettent de convertir un nombre hexadecimal 
  respectivement en : octal, binaire et decimal
*/
//Cette fonction convertit un nombre hexadecimal en octal, elle renvoie un "string"
string hexa_to_octal(string number)
{
    string result = "";
    string num = format_hexa_number(number);
    result = binary_to_octal(hexa_to_binary(num));
    
    return result;
}

//Cette fonction convertit un nombre hexadecimal en binaire, elle renvoie un "string"
string hexa_to_binary(string number)
{
    string result = "";
    string num = format_hexa_number(number);
    for(int i(0); i<num.size(); i++)
    {       
      switch(num[i])
      {
        case '0':
          result += "0000";
          break;
        case '1':
          result += "0001";
          break;
          case '2':
          result += "0010";
          break;
        case '3':
          result += "0011";
          break;
        case '4':
          result += "0100";
          break;
        case '5':
          result += "0101";
          break;
          case '6':
          result += "0110";
          break;
        case '7':
          result += "0111";
          break;
        case '8':
          result += "1000";
          break;
        case '9':
          result += "1001";
          break;
          case 'A':
          result += "1010";
          break;
        case 'B':
          result += "1011";
          break;
        case 'C':
          result += "1100";
          break;
        case 'D':
          result += "1101";
          break;
          case 'E':
          result += "1110";
          break;
        case 'F':
          result += "1111";
          break;           
      }
    }
    result = format_number(result);
    return result;
}

//Cette fonction convertit un nombre hexadecimal en decimal, elle renvoie un "int"
int hexa_to_decimal(string number)
{
  int result = 0;
  string num = format_hexa_number(number);
  result = binary_to_decimal(hexa_to_binary(num));
  return result;
}
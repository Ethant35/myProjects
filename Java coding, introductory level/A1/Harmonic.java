public class Harmonic {
  public static void main(String[] args) {
//printing what my Harmonic sum returns using iteration
    for (int i=1;i<=20;i++){ 
      System.out.println(calcIterativeHarmonic(i));
    }
//printing what my Harmonic sum returns using iteration
    for (int i=1;i<=20;i++){
      System.out.println(calcRecursiveHarmonic(i));
    }
  }
//Declaration of calculating harmonic number using iterating
  public static double calcIterativeHarmonic(int n){
//Variable for storing the harmonic number
    double sumOfHarmonics = 0;
//Variable using for iterating
    int i;
//For loop using n value to iterate and add the correct amount of Harmonic numbers
    for (i = 1; i <= n; ++i){
//Using the formula for Harmonics to add the Harmonic number at 1 to my subOfHarmonic variable
      sumOfHarmonics+=1.0/i;
    }
    return sumOfHarmonics;
  }

//Declaring the recursive Harmonic calculation
  public static double calcRecursiveHarmonic(int n){
//Base case that breaks out when n is 1
    if (n == 1 ){
      return 1;
    }
//Else case that does the Harmonic calculation using the calcRecursiveHarmonic method
    else{
      return (1.0 / n) + (calcRecursiveHarmonic(n - 1));
    }
  }
}

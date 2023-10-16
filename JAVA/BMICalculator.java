import java.util.Scanner;

public class BMICalculator {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
  
    System.out.print("Enter your weight (kg): ");
    double weight = scanner.nextDouble();
  
    System.out.print("Enter your height (m): ");
    double height = scanner.nextDouble();
  
    double bmi = calculateBMI(weight, height);
    System.out.println("Your BMI is: " + bmi);
  
    getCategory(bmi);
  
    scanner.close();
  }

  public static double calculateBMI(double weight, double height) {
    return weight / (height * height);
  }

  public static void getCategory(double bmi) {
      if (bmi < 18.5) {
          System.out.println("Underweight");
      } else if (bmi < 24.9) {
          System.out.println("Normal Weight");
      } else if (bmi < 29.9) {
          System.out.println("Overweight");
      } else {
          System.out.println("Obesity");
      }
  }
}

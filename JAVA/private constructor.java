class Language {

  // create a public static variable of class type
  private static Language language;

  // private constructor
  private Language() {
    System.out.println("Inside Private Constructor");
  }

  // public static method
  public static Language getInstance() {

     // create object if it's not already created
     if(language == null) {
        language = new Language();
     }

      // returns the singleton object
      return language;
  }

  public void display() {
      System.out.println("Singleton Pattern is achieved");
  }
}

class Main {
  public static void main(String[] args) {
     Language db1;

     // call the getInstance method
     db1= Language.getInstance();

     db1.display();
  }
}

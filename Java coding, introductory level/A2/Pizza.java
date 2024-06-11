/*
Ethan Tarnarider
2365982
tarnarider@chapman.edu
CPSC 231-02
MP2
*/
public class Pizza {
  //Pizza class, assigns, mutates and is able to create all the pizza objects neceessary for PizzaDriver to work
  //Additionally creates some of the logic in figuring out if two pizzas are equivalent and calculating the cost of a pizza
  //Member variable that stores a string that is the size of the pizza 
    private String m_pizzaSize;
  //Integer that stores the number of cheese toppings on a pizza 
    private int m_cheeseToppings;
  //Integer that stores the number of pepperoni toppings on a pizza 
    private int m_pepperoniToppings;
  //Integer that stores the number of veggie toppings on a pizza  
    private int m_veggieToppings;

  //Overload constructor that creates a pizza object and sets the size, cheese, pepperoni and veggies  
    public Pizza(String pizzaSize, int cheeseToppings, int pepperoniToppings, int veggieToppings){
        m_pizzaSize=pizzaSize;
        m_cheeseToppings=cheeseToppings;
        m_pepperoniToppings=pepperoniToppings;
        m_veggieToppings=veggieToppings;
    }
    
  //Default constructor  
    public Pizza(){
        m_pizzaSize="";
        m_cheeseToppings=0;
        m_pepperoniToppings=0;
        m_veggieToppings=0;
    }

   

  //Copy constructor that takes an instance of a pizza and copies it  
    public Pizza(Pizza otherPizza){
        m_pizzaSize=otherPizza.m_pizzaSize;
        m_cheeseToppings=otherPizza.m_cheeseToppings;
        m_pepperoniToppings=otherPizza.m_pepperoniToppings;
        m_veggieToppings=otherPizza.m_veggieToppings;

    }

  //Method that calculates the cost of a pizza based on the money values given and does the calculation and returns a double  
    public double calcCost(Pizza pizza){
  //Cost variable that is added to based on what a specific pizza has      
      int cost = 0;
        int numToppings=m_cheeseToppings+m_pepperoniToppings+m_veggieToppings;
        int toppingsCost=2*numToppings;
  //Switch statement that is fed in the size of a pizza and adds different numbers the cost based on the size      
        switch (m_pizzaSize){
            case ("Small"):
                cost+=10;
                break;
            case ("Medium"):
                cost+=12;
                break;
            case ("Large"):
                cost+=14;
                break;
        }
        cost+=toppingsCost;
        return cost;


    }

  //To string method that returns relevant data about a pizza  
    public String toString(){
        String s = "";
        s += "Size: " + m_pizzaSize;
        s += "\nCheese toppings: " +m_cheeseToppings;
        s += "\nPepperoni toppings: " +m_pepperoniToppings;
        s += "\nVeggie toppings: " +m_veggieToppings;
              return s;
          
    }

  //Equals method that allows you to comapre two pizzas and returns true if they are equal and false if they are not  
    public boolean equals(Object o) {
        if (this == o) {
          return true;
        }
        if (!(o instanceof Pizza)) {
          return false;
        }
        Pizza p = (Pizza) o;
        return ((this.m_pizzaSize.equals(p.m_pizzaSize)) && (this.m_cheeseToppings == (p.m_cheeseToppings)) && (this.m_pepperoniToppings == (p.m_pepperoniToppings)) && (this.m_veggieToppings == (p.m_veggieToppings)));
      }

  //Pizza size getter  
      public String getpizzaSize() {
        return m_pizzaSize;
      }
  //Pizza size setter    
      public void setpizzaSize(String pizzaSize) {
        m_pizzaSize = pizzaSize;
      }
    //Cheese toppings getter 
      public int getcheeseToppings() {
        return m_cheeseToppings;
      }
    //Cheese toppings setter   
      public void setcheeseToppings(int cheeseToppings) {
        m_cheeseToppings = cheeseToppings;
      }
    //Pepperoni toppings getter 
      public int getpepperoniToppings  () {
        return m_pepperoniToppings;
      }
    //Pepperoni toppings setter   
      public void setpepperoniToppings(int pepperoniToppings) {
        m_pepperoniToppings = pepperoniToppings;
      }
    //Veggie toppings getter 
      public int getveggieToppings() {
        return m_veggieToppings;
      }
    //Veggie toppings setter   
      public void setveggieToppings(int veggieToppings) {
        m_veggieToppings = veggieToppings;
      }    
}

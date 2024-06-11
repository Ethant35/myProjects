/*
Ethan Tarnarider
2365982
tarnarider@chapman.edu
CPSC 231-02
MP2
*/
public class PizzaDriver {
//Pizza driver class that creates pizza objects with various construction, adds them to the orders array, tests if pizzas are equal
//and uses to toString method
    public static void main(String[] args) {
        //Pizza Pizza = new Pizza();
        //PizzaOrder Order= new PizzaOrder();
        Pizza pizza1 = new Pizza("Small",1,0,1);// Code to create a small pizza, 1 cheese, 1 veggie
        Pizza pizza2 = new Pizza("Large",2,2,0);// Code to create a large pizza, 2 cheese, 2 pepperoni 
        Pizza pizza3 = new Pizza(pizza2);// Same as pizza 2, use copy constructor
        Pizza pizza4 = new Pizza(pizza1);// Same as pizza 1, use copy constructor
        PizzaOrder order = new PizzaOrder(3);// Code to create an order of THREE pizzas
        System.out.println(order.addPizza(pizza1)); // add pizza1 to the order 
        System.out.println(order.addPizza(pizza2));// add pizza2 to the order
        System.out.println(order.addPizza(pizza3)); // add pizza3 to the order  
        System.out.println(order.addPizza(pizza4)); // add pizza4 to the order – 									what happens here?
        System.out.println(pizza1.equals(pizza3));
        System.out.println(order.toString()); //Call order’s toString method
        System.out.println(order.calcTotal(order)); //Using calcTotal which is a wrapper method of the cost method in Pizza for an order of pizzas
        
    }
}

/*
Ethan Tarnarider
2365982
tarnarider@chapman.edu
CPSC 231-02
MP2
*/
public class PizzaOrder {
//Pizza order class that handles putting objects of type pizza into an array of type pizza
//private array of type pizza, named m_order
    private Pizza[] m_order;
//Default constructor   
    public PizzaOrder(){   
        m_order=new Pizza[1];
        m_order[0]=new Pizza("Small",0,0,0);
        }
//Overloaded constructor that allows you to set the m_order array to any size you would like        
    public PizzaOrder(int orderSize){
        m_order=new Pizza[orderSize];
    }

//Method addPizza that returns an integer, 1 if it was able to successfully add the pizza into the array and -1 if it wasn't able to add the pizza     
    public int addPizza(Pizza pizza){
//For loop iterating over every pizza in m_order        
        for (int i=0;i<m_order.length;i++){
//Checking if an index is null and if it is, then a pizza can be added into that index            
            if (m_order[i]==null){
                m_order[i]=pizza;
                return 1;
            }
            
        }
        return -1;
    }

//calcTotal method that returns a double and iterates through the pizzas in the m_order array and uses the calcCost method 
//from the pizza class    
    public double calcTotal(PizzaOrder pizzaArray){
        double totalCost=0;
        for (int i=0;i<m_order.length;i++){
            if (m_order[i]!=null){
                totalCost+=m_order[i].calcCost(m_order[i]);
            }
            
    }
    return totalCost;

    }

//Method that turns the indices of an array into a string returns them so they can be used in a toString method properly
//instead of just returning memory addresses    
    public String arrayToString(Pizza[] array){
            String aP="";
            for (int i = 0; i<array.length; i++){
              if(array[i]!= null){
                aP+=" \n"+i+" "+array[i].getpizzaSize()+" "+array[i].getcheeseToppings()+" "+array[i].getpepperoniToppings()+" "+array[i].getveggieToppings();
              }
              else{
                aP+="\n"+i+" "+"Null";
              }
        
        
            }
            return aP;
    }

//toString method that returns a string that just uses the arrayToStrung method on the array of pizzas, m_order    
    public String toString(){
        return arrayToString(m_order);
        
    }
}


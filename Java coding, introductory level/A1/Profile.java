public class Profile {
//Initializing first 2 member variables, string and int m_name and m_age
  private String m_name;
  private int m_age;
//Initializing two arrays, both of type profile and size 10
  private Profile[] m_swipedR = new Profile[10];
  private Profile[] m_matches = new Profile[10];

  //Default constructor
  public Profile() {
    m_name = "";
    m_age = 0;
  }

  //Overload constructor
  public Profile(String name, int age, Profile[] swipedR, Profile[] matches) {
    m_name = name;
    m_age = age;
    m_swipedR = swipedR;
    m_matches = matches;
  }


//Name accessor followed by mutator
  public String getName() {
    return m_name;
  }
  public void setName(String name) {
    m_name = name;
  }
//Age accessor followed by mutator
  public int getAge() {
    return m_age;
  }
  public void setAge(int age) {
    m_age = age;
  }
  //SwipedR accessor followed by mutator
  public Profile[] getSwipedR() {
    return m_swipedR;
  }
  public void setSwipedR(Profile[] swipedR) {
    m_swipedR = swipedR;
  }
  //Matches accessor followed by mutator
  public Profile[] getMatches() {
    return m_matches;
  }
  public void setMatches(Profile[] matches) {
    m_matches = matches;
  }

//ArrayToString method that allows me to print my arrays as a string instead of just the memory address
  public String arrayToString(Profile[] array){
//Variable for holding array content
    String aS="";
//For loop iterating through the array and adding it to the aS variable
    for (int i = 0; i<array.length; i++){
//If statement checking if the index is null
      if(array[i]!= null){
        aS+=" \n"+i+" "+array[i].m_name+" "+array[i].m_age;
      }
//Else statement so if the index is null, it adds "null" instead of throwing an exception
      else{
        aS+="\n"+i+" "+"Null";
      }


    }
    return aS;
  }

  //public method toString() containing appropriate description of Profile
  public String toString() {
    String s = "";
    s += "Name: " + m_name;
    s += "\nAge: " +m_age;
    s += "\nSwiped Right: " + " "+arrayToString(m_swipedR)+" ";
    s += "\nMatches: " + " "+arrayToString(m_matches)+" ";
      return s;
  }

  //public method equals() that determines whether two profiles are the same and returns a boolean
  public boolean equals(Object o) {
    if (this == o) {
      return true;
    }
    if (!(o instanceof Profile)) {
      return false;
    }
    Profile p = (Profile) o;
    return ((this.m_name.equals(p.m_name)) && (this.m_age == (p.m_age)));
  }

//Method to check if a a match (two profiles liking each other) exists
  public boolean matchExists(Profile otherProfile){
//Checking if the passed in profile is equal to the other profile's like list
      Profile[] otherSwipedR=otherProfile.getSwipedR();
//For loop iterating through the other profile like list
      for (int i = 0; i < otherSwipedR.length; i++){
//If statement that returns true if the index is not null and the index is equal to any index of the object it was called on
        if (otherSwipedR[i]!=null&&otherSwipedR[i].equals(this)){
          return true;
        }
      }
    return false;
  }

//Method for adding a profile to either array of a different profile
  public boolean addToProfileList(Profile profile,Profile[] profileList){
//Iterating through either the like or match array and seeing if there is a match between the profile passed in and the
//contents of the like or match list passed in
    for (int i = 0; i < profileList.length; i++){
        profileList[i] = profile;
        return true;
      }
      return false;
    }

//Method to add a profile to another's swipe right list and checks for a match as well
  public void swipeRight(Profile profile) {
//Adding a profile to antother profiles like list
    addToProfileList(profile,m_swipedR);
//Logic to check for matches, matchExists method to see if there is a commonality beteen the passed in profile and the profile
//that swipeRight was called on
        if (this.matchExists(profile)){

//If statement in the condition that the match array is full
          if(addToProfileList(this,profile.getMatches())==false){
            System.out.println("The match cannot be made");
          }
          else{
            System.out.println("Match was made");
          }

          if(addToProfileList(profile,m_matches)==false){
            System.out.println("The match cannot be made.");
          }
          else{
            System.out.println("Match was made");

          }
        }
  }

//Method for removing a profile from another profile's like array
  public void swipeLeft(Profile otherProfile) {
//Iterating through that profile's like list
      for (int i = 0; i < m_swipedR.length; i++){
//Checking that it is not null and that it is equivalent
        if (m_swipedR[i]!=null && m_swipedR[i].equals(otherProfile)){
//Changing that entry of a like to a null entry
          m_swipedR[i]=null;
          return;
        }
      }
    }

  //main method where program reads the 2 profiles and simulates matching:
  public static void main (String[] args) {
//sample profile 1
    Profile p2 = new Profile("Ethan", 20, new Profile[10],new Profile[10]); //sample profile 1
//sample profile 2
    Profile p3 = new Profile("Nicole", 19, new Profile[10],new Profile[10]);
    Profile p4 = new Profile("Felix", 20, new Profile[10], new Profile[10]);
    p2.swipeRight(p3);
    System.out.println("P2 should have p3 in swipe right but not match "+p2.toString());
    System.out.println("P3 after swipe right, should not have match yet "+p3.toString());
    p2.swipeRight(p4);
    System.out.println("Profile 2 after they liked profiles 3 and 4 "+p2.toString());
    p2.swipeLeft(p3);
    System.out.println("Profile 2 after it swiped left on profile 3 "+p2.toString());
    p2.swipeRight(p3);
    System.out.println("Profile 2 added p3"+p2.toString());
    System.out.println("P3 after added by p2"+p3.toString());
    p3.swipeRight(p2);
    System.out.println("Profile 2 after it matches with profile 3 "+p2.toString());
    System.out.println("Profile 3 after it matches with profile 2 "+p3.toString());





  }

}

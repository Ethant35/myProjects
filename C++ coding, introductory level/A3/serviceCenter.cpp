#include "serviceCenter.h"


serviceCenter::~serviceCenter(){

}
serviceCenter::serviceCenter(int numr,int numc,int numf){
    regis=new Office(numr);
    cash=new Office(numc);
    faid=new Office(numf);
}
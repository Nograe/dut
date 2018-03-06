class Premiere{
    Premiere(){
	System.out.println("constructeur de Premiere");
    }
}
class Seconde extends Premiere{
    Seconde(boolean b){
	super();
	System.out.println("constructeur de Seconde");
    }
}
class Troisieme extends Premiere{
    Troisieme(int i){
	super();
	System.out.println("constructeur de Troisieme");
    }
}
class Quatrieme extends Troisieme{
    Quatrieme(double d){
	super(14);
	System.out.println("constructeur de Quatrieme");
    }
}

class Cinquieme extends Premiere{
    Cinquieme(){
	System.out.println("constructeur de Cinquieme");
    }
}
class Sixieme extends Cinquieme{
    Sixieme(){
	System.out.println("constructeur de Sixieme");
    }
}
class ex1 {
    public static void main(String[] args){
	new Cinquieme();
	System.out.println("=============================");
	new Sixieme();
    }
}

// class ex1 {
//     public static void main(String[] args){
// 	new Premiere();
// 	System.out.println("=============================");
// 	new Seconde(true);
// 	System.out.println("=============================");
// 	new Troisieme(15);
// 	System.out.println("=============================");
// 	new Quatrieme(12.3);
//     }
// }

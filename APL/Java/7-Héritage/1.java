class Premiere{
    Premiere(){
	Terminal.ecrireStringln("constructeur de Premiere");
    }
}
class Seconde extends Premiere{
    Seconde(boolean b){
	super();
	Terminal.ecrireStringln("constructeur de Seconde");
    }
}
class Troisieme extends Premiere{
    Troisieme(int i){
	super();
	Terminal.ecrireStringln("constructeur de Troisieme");
    }
}
class Quatrieme extends Troisieme{
    Quatrieme(double d){
	super(14);
	Terminal.ecrireStringln("constructeur de Quatrieme");
    }
}
class ex1 {
    public static void main(String[] args){
	new Premiere();
	Terminal.ecrireStringln("=============================");
	new Seconde(true);
	Terminal.ecrireStringln("=============================");
	new Troisieme(15);
	Terminal.ecrireStringln("=============================");
	new Quatrieme(12.3);
    }
}

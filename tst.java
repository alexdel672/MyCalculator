import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;
import javax.script.ScriptException;



public class tst {
  public static void main(String[] args) throws ScriptException {
	
    ScriptEngineManager mgr = new ScriptEngineManager();
    ScriptEngine engine = mgr.getEngineByName("JavaScript");
    String foo = "(5+5 - 5) 5)";
    String x = foo;
    try {
    System.out.println(engine.eval(x));
    }catch(Exception e) {
    	System.out.println("Expression passed is not valid");
    }
    } 
}


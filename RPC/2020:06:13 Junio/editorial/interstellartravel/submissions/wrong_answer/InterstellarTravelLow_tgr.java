import java.util.* ;
public class InterstellarTravelLow_tgr {
   final static double TAU = 2 * Math.PI ;
   static double circabs(double a) {
      a %= TAU ;
      if (a > Math.PI)
         return TAU - a ;
      return a ;
   }
   static class Inflection implements Comparable {
      Inflection(double a_, double b_) {
         a = a_ ;
         b = b_ ;
      }
      public int compareTo(Object o) {
         Inflection c = (Inflection)o ;
         if (a < c.a)
            return -1 ;
         if (a > c.a)
            return 1 ;
         return 0 ;
      }
      double a, b ;
   }
   static Vector<Inflection> infs = new Vector<Inflection>() ;
   static void addslope(double where, double val) {
      infs.add(new Inflection(where, val)) ;
   }
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in) ;
      int n = sc.nextInt() ;
      double curslope = 0 ;
      double curval = 0 ;
      for (int i=0; i<n; i++) {
         double t = sc.nextDouble() ;
         double s = sc.nextDouble() ;
         double a = sc.nextDouble() ;
         addslope(a, -2*s) ;
         if (s * Math.PI <= t) { // note: s=0 case handled here
            double aprime = (a + Math.PI) % TAU ;
            addslope(aprime, 2*s) ;
            if (a < aprime)
               curslope += s ;
            else
               curslope -= s ;
         } else {
            double ts = t / s ;
            double a0 = (a - ts + TAU) % TAU ;
            if (a0 < 0)
               a0 = (a0 + TAU) % TAU ;
            double a1 = (a + ts) % TAU ;
            addslope(a0, s) ;
            addslope(a1, s) ;
            if (a < a0 && a < a1)
               curslope += s ;
            else if (a1 < a && a1 < a0)
               curslope -= s ;
         }
         curval += Math.max(0, t-s*circabs(a)) ;
      }
      double r = curval ;
      double curpt = 0 ;
      Collections.sort(infs) ;
      for (Inflection inf : infs) {
         curval += curslope * (inf.a - curpt) ;
         r = Math.max(r, curval) ;
         double testval = 0 ;
         curpt = inf.a ;
         curslope += inf.b ;
      }
      double EPS = 1.1e-6 ;
      r *= (1 - EPS) ;
      System.out.println(r) ;
   }
}

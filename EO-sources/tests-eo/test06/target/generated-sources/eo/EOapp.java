
/*
 * This file was auto-generated by eolang-maven-plugin
 * on 2021-09-08T07:25:45.543+03:00. Don't edit it,
 * your changes will be discarded on the next build.
 * The sources were compiled to XML on
 * 2021-09-08T04:25:39.788372Z by the EO compiler v.0.1.19.
 */

package test06;

import org.eolang.*;
import org.eolang.phi.*;

public final class EOapp extends PhDefault {
  public EOapp() {
    this(new PhEta());
  }
  public EOapp(final Phi parent) {
    super(parent);
    this.add("φ", new AtBound(new AtOnce(new AtLambda(this, self -> {
      Phi ret_base = new EOglobal(self);
      Phi ret = new PhMethod(ret_base, "main");
      return ret;
    }))));
  }
}

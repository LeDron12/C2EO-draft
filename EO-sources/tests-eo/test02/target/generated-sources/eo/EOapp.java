
/*
 * This file was auto-generated by eolang-maven-plugin
 * on 2021-08-23T08:19:31.801+03:00. Don't edit it,
 * your changes will be discarded on the next build.
 * The sources were compiled to XML on
 * 2021-08-23T05:19:26.158835Z by the EO compiler v.0.1.19.
 */

package test02;

import org.eolang.*;
import org.eolang.phi.*;

public final class EOapp extends PhDefault {
  public EOapp() {
    this(new PhEta());
  }
  public EOapp(final Phi parent) {
    super(parent);
    this.add("value", new AtBound(new AtOnce(new AtLambda(this, self -> {
      Phi ret = new EOcover(self);
      ret = new PhCopy(ret);
        Phi ret_1 = new org.eolang.EOint(self);
        ret_1 = new PhCopy(ret_1);
          ret_1 = new PhWith(ret_1, "Δ", new Data.Value<Long>(555L));
        ret = new PhWith(ret, 0, ret_1);
      return ret;
    }))));
    this.add("φ", new AtBound(new AtOnce(new AtLambda(this, self -> {
      Phi ret = new org.eolang.io.EOstdout(self);
      ret = new PhCopy(ret);
        Phi ret_1 = new org.eolang.txt.EOsprintf(self);
        ret_1 = new PhCopy(ret_1);
          Phi ret_1_1 = new org.eolang.EOstring(self);
          ret_1_1 = new PhCopy(ret_1_1);
            ret_1_1 = new PhWith(ret_1_1, "Δ", new Data.Value<String>("%d\n"));
          Phi ret_1_2 = new PhMethod(self, "value");
          ret_1 = new PhWith(ret_1, 0, ret_1_1);
          ret_1 = new PhWith(ret_1, 1, ret_1_2);
        ret = new PhWith(ret, 0, ret_1);
      return ret;
    }))));
  }
}

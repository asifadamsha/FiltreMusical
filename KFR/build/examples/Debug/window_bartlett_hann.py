#!/usr/bin/env python
import dspplot

data = [
                   0,
0.0095073529801951162,
0.022772549855648638,
0.039739476658409378,
 0.06031522996543548,
0.084371040214551163,
 0.11174355147420773,
 0.14223644494812177,
  0.1756223900796734,
 0.21164530386510985,
 0.25002289592148763,
 0.29044947401532184,
 0.33259898216934125,
 0.37612824115327714,
 0.42068035915323315,
 0.46588827872287303,
 0.51137842476522954,
 0.55677441728985377,
 0.60170081204625658,
 0.64578683185754482,
 0.68867005157058481,
 0.72999999999999998,
 0.76944164306826779,
 0.80667871352490184,
  0.8414168541524768,
 0.87338654322090092,
 0.90234577311545716,
 0.92808245551720492,
 0.95041652923197839,
 0.96920174971943052,
  0.9843271425369774,
 0.99571810625366663,
 0.99571810625366663,
 0.98432714253697751,
 0.96920174971943063,
 0.95041652923197839,
 0.92808245551720514,
 0.90234577311545738,
 0.87338654322090115,
  0.8414168541524768,
 0.80667871352490195,
 0.76944164306826801,
  0.7300000000000002,
 0.68867005157058481,
 0.64578683185754493,
 0.60170081204625681,
   0.556774417289854,
 0.51137842476522954,
 0.46588827872287325,
 0.42068035915323343,
  0.3761282411532772,
 0.33259898216934125,
 0.29044947401532206,
 0.25002289592148802,
 0.21164530386511007,
  0.1756223900796734,
 0.14223644494812177,
 0.11174355147420789,
0.084371040214551329,
 0.06031522996543548,
0.039739476658409489,
0.022772549855648638,
0.0095073529801951162,
                   0,
]
dspplot.plot(data, freqresp=True, dots=True, padwidth=1024, log_freq=False, horizontal=False, normalized_freq=True, title='Bartlett-Hann window', file='../svg/window_bartlett_hann.svg')

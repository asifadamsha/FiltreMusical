#!/usr/bin/env python
import dspplot

data = [
3.8981718325193699e-17,
 0.03273255876723298,
 0.06734793569901884,
 0.10369964244185177,
 0.14162701917995243,
  0.1809561712947077,
 0.22150101264193159,
 0.26306440827386562,
 0.30543940860783875,
 0.34841056627902411,
 0.39175532621725612,
 0.43524547886339943,
 0.47864866589467076,
 0.52172992736535628,
  0.5642532787936152,
 0.60598330643986298,
 0.64668676883020448,
 0.68613419248136964,
 0.72410144978265956,
 0.76037130708578549,
 0.79473493124464478,
 0.82699334313268824,
 0.85695880704345373,
 0.88445614534720718,
 0.90932396832975038,
  0.9314158097740256,
 0.95060115955607594,
 0.96676638530855219,
 0.97981553605101657,
 0.98967102158995235,
 0.99627416244535894,
 0.99958560605736568,
 0.99958560605736568,
 0.99627416244535871,
 0.98967102158995235,
 0.97981553605101646,
 0.96676638530855219,
 0.95060115955607605,
 0.93141580977402549,
 0.90932396832975027,
 0.88445614534720707,
 0.85695880704345362,
 0.82699334313268791,
 0.79473493124464478,
 0.76037130708578526,
 0.72410144978265956,
 0.68613419248136953,
 0.64668676883020448,
 0.60598330643986276,
 0.56425327879361475,
 0.52172992736535617,
 0.47864866589467048,
 0.43524547886339943,
 0.39175532621725595,
 0.34841056627902411,
 0.30543940860783853,
 0.26306440827386524,
 0.22150101264193142,
 0.18095617129470734,
 0.14162701917995243,
 0.10369964244185162,
 0.06734793569901884,
0.032732558767232828,
3.8981718325193699e-17,
]
dspplot.plot(data, freqresp=True, dots=True, padwidth=1024, log_freq=False, horizontal=False, normalized_freq=True, title='Lanczos window', file='../svg/window_lanczos.svg')

10 col= 7
20 row= 7
25 g=0
30 dim ow%(col,row)
40 dim nw%(col,row)
50 ow%(2,3)= 1:ow%(3,1)=1:ow%(3,3)=1:ow%(4,2)=1:ow%(4,3)=1
60 rem small glider
100 print"{clear}";: rem print array
120 print"{red}"; :rem ctrl 1
130 print "generation",g
140 print"{white}"; :rem ctrl 6
150 for y = 0 to row
160 for x = 0 to col
170 ifow%(x,y)=1then print"1"; :goto 190
180 print".";
190 nextx:print
200 nexty
300 gosub 1000
325 g=g+1
350 goto 100
1000 rem add neighbors
1150 for y = 0 to row
1160 for x = 0 to col
1165 n =0
1175 for i=-1 to 1
1185 for j=-1 to 1: n=n+ ow%((x+i+8)and7 ,(y+j+8)and7):nextj:nexti:n=n-ow%(x,y)
1190 if ow%(x,y)= 1 and n <2 then nw%(x,y)=0:goto1290
1200 if ow%(x,y)= 1 and n >3 then nw%(x,y)=0:goto1290
1210 if ow%(x,y)= 0 and n =3 then nw%(x,y)=1:goto1290
1220 nw%(x,y)=ow%(x,y) :rem no change
1290 nextx
1300 nexty
1305 rem copy arrays
1350 for y = 0 to row
1360 for x = 0 to col
1370 ow%(x,y)=nw%(x,y)
1380 next x
1390 next y
1400 return
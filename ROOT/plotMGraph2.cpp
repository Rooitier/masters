void multigraph(const char* file1, const char* file2){
   TCanvas *c1 = new TCanvas("c1","multigraph",700,500);
   c1->SetGrid();

   TMultiGraph *mg = new TMultiGraph();
   enum { Num1 = 8, Num2 = 40 };


   // create first graph
   float_t x[Num1], y[Num1], yl[Num1];

   ifstream in;
   in.open(file1);
   
   for( int i = 0; i < Num1; ++i ){

    in >> x[i] >> y[i];
    yl[i] = log(y[i]);
    }

   TGraph *gr1 = new TGraph(8, x, yl);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(21);
   mg->Add(gr1);

   // create second graph
   float_t e[Num2], a[Num2], s[Num2], t[Num2], tl[Num2], j1[Num2], j2[Num2], j3[Num2], j4[Num2], j5[Num2], j6[Num2], j7[Num2], j8[Num2], j9[Num2];

   ifstream in2;
   in2.open(file2);

   for (int i = 0; i < Num2; ++i ){
    in2 >> e[i] >> a[i] >> s[i] >> t[i] >> j1[i] >> j2[i] >> j3[i] >> j4[i] >> j5[i] >> j6[i] >> j7[i] >> j8[i] >> j9[i];
    
    tl[i] = log(t[i]);
    cout << t[i];
    }

    TGraph *gr2 = new TGraph(40, e, tl);
    gr2->SetMarkerColor(kRed);
    gr2->SetMarkerStyle(20);
    mg->Add(gr2);

   mg->Draw("apl");
   mg->GetXaxis()->SetTitle("Energy (MeV)");
   mg->GetYaxis()->SetTitle("Log(no. of nuclear level density states)");

   gPad->Update();
   gPad->Modified();
}
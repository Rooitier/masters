{

  enum { kNumData = 8 };

  Float_t x[kNumData];
  Float_t y[kNumData];
  float_t yl[kNumData];

  ifstream in;
  in.open( "nndc_data" );

  for( int i = 0; i < kNumData; ++i ){

    in >> x[i] >> y[i];
    yl[i] = log(y[i]);
  }

  enum { Num2 = 40};

  float_t e[Num2], a[Num2], s[Num2], t[Num2], tl[Num2], j1[Num2], j2[Num2], j3[Num2], j4[Num2], j5[Num2], j6[Num2], j7[Num2], j8[Num2];

  ifstream in2;
  in2.open("nlddata");

  for (int i = 0; i < Num2; ++i )
  {
    in2 >> e[i] >> a[i] >> s[i] >> t[i] >> j1[i] >> j2[i] >> j3[i] >> j4[i] >> j5[i] >> j6[i] >> j7[i] >> j8[i];
    tl[i] = log(t[i]);
  }
  
  


  TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
  TGraph *gr1 = new TGraph(8, x, yl);
  TGraph *gr2 = new TGraph(40, e, tl);

  //setup labels
  gr2->GetXaxis()->SetTitle( "Energy (MeV)" );
  gr2->GetYaxis()->SetTitle( "Log(Number of nuclear levels)" );
  gr1->SetMarkerSize(3);
  gr1->SetLineWidth(2);
  gr1->SetTitle("Blank");
  gr2->SetLineWidth(2);
  gr2->SetMarkerSize(3);
  gr2->SetLineColor(2);

  gr2->Draw("APL");
  gr1->Draw("PL");





}



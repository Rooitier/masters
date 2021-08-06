{


  TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
  T1HF *h1 = new T1HF("h1","h1 options", 3000,0,40,3000,0,100);
  T1HF *h2 = new T1HF("h2","h2 options", 3000,0,40,3000,0,100);
  int kNumData = 8;

  int x;
  int y;


  ifstream in;
  in.open( "nndc_data" );

  for( int i = 0; i < kNumData; ++i ){

    in >> x >> y;
    h1->Fill(i,y);
  }

  int Num2 = 40;

  int e, a, s, t, j1, j2, j3, j4, j5, j6, j7, j8;

  ifstream in2;
  in2.open("nlddata");

  for (int i = 0; i < Num2; ++i )
  {
    in2 >> e >> a >> s >> t >> j1 >> j2 >> j3 >> j4 >> j5 >> j6 >> j7 >> j8;
  }
  
  int el;
  int tl;

  for (int i = 0; i < Num2; i++)
  {
  
    tl = log(t);
  }
  


//   TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
//   TGraph *gr1 = new TGraph(8, x, y);
//   TGraph *gr2 = new TGraph(29, e, tl);

//   //setup labels
//   gr1->GetXaxis()->SetTitle( "Energy (MeV)" );
//   gr1->GetYaxis()->SetTitle( "Number of nuclear levels" );
//   gr1->SetMarkerSize(3);
//   gr1->SetLineWidth(2);
//   gr1->SetTitle("Blank");
//   gr2->SetLineWidth(2);
//   gr2->SetMarkerSize(3);
//   gr2->SetLineColor(2);

//   gr1->Draw("APL");
//   gr2->Draw("PL");




}



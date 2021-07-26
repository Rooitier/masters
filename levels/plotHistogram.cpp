{

  Int_t numData = 100;

  TH1F hist( "hist", "Poisson Stats", 30, 35.5, 65.5 );

  hist.GetXaxis()->SetTitle( "Number of Counts per Run" );
  hist.GetYaxis()->SetTitle( "Number of Runs" );

  ifstream in;
  in.open( "data" );

  // the value to read in
  int value;

  for( int i = 1; i <= numData; ++i ){

    in >> value;

    hist.Fill( value );
  }

  // draw the spectrum with error bars
  hist.Draw( "E" );
}



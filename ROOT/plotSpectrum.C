{

  Int_t numData = 512;

  TH1F spectrum( "spectrum", "Gamma Spectrum", 512, -0.5, 511.5 );

  spectrum.GetXaxis()->SetTitle( "Channels" );
  spectrum.GetYaxis()->SetTitle( "Counts per Channel" );

  ifstream in;
  in.open( "cs137_spe" );

  // the value to read in
  int value;

  for( int i = 1; i <= numData; ++i ){

    in >> value;

    // set the bin contents and error according to the value we read in
    spectrum.SetBinContent( i, value );
    spectrum.SetBinError( i, sqrt( value ) );
  }

  // draw the spectrum with error bars
  spectrum.Draw( "E" );
}


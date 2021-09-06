void plot(const char* file1, const char* file2){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
c1->SetLogy();

TMultiGraph *mg = new TMultiGraph("mg","Energy (MeV) versus No. of nuclear level density states");

TGraph *gr = new TGraph(file1, "%lg %lg");
TGraph *gr1 = new TGraph(file2, "%lg %lg %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s");

// Options
gr->SetMarkerColor(2);
gr->SetMarkerStyle(20);
gr->SetLineColor(2);

gr1->SetMarkerColor(4);
gr1->SetMarkerStyle(20); 


mg->Add(gr);
mg->Add(gr1);

mg->GetXaxis()->SetRangeUser(0,20);
mg->GetYaxis()->SetRangeUser(1E-3,1E6);


mg->GetXaxis()->SetTitle("Energy (MeV)");
mg->GetYaxis()->SetTitle("No. of nuclear level density states");

//Draw

mg->Draw("APL");

gPad->Modified();
gPad->Update();

}
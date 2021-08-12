void plot(const char* file1, const char* file2){

TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
TMultiGraph *mg = new TMultiGraph("mg","Energy (E) versus Log( #font[12]{f}(E_{1})) (arb. units)");

TGraphErrors *gr = new TGraphErrors(file1, "%lg %lg");

TGraphAsymmErrors *gr1 = new TGraphAsymmErrors(file2, "%lg %*s %lg %lg %lg");
TGraphAsymmErrors *gr2 = new TGraphAsymmErrors(gr1->GetN(),gr1->GetX(),gr1->GetY(),gr1->GetEXlow(),gr1->GetEXhigh(),gr1->GetEYhigh(),gr1->GetEYlow());


gr->SetMarkerColor(2);
gr->SetMarkerStyle(20);
gr->SetLineColor(2);

gr2->SetMarkerColor(4);
gr2->SetMarkerStyle(20);


// TGraphErrors *gr3 = new TGraphErrors(file3, "%lg %lg");
// gr3->SetMarkerColor(6);
// gr3->SetMarkerStyle(20);
// mg->Add(gr3,"PL");


mg->Add(gr, "PL");
mg->Add(gr2, "P");

mg->GetXaxis()->SetRangeUser(1E-12, 13);
mg->SetMinimum(1E-12);
mg->GetXaxis()->SetTitle("Energy (MeV)");
mg->GetYaxis()->SetTitle("Log(#font[12]{f}(E_{1})) (arb. units)");
//mg->SetTitle("Neutron number (N) versus Resonance spacing D_{0}");

mg->Draw("AP");
c1->SetLogy(1);
gPad->Update();
gPad->Modified();
}
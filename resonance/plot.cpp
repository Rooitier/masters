void plot(const char* file1, const char* file2){
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);

TMultiGraph *mg = new TMultiGraph();

TGraphErrors *gr = new TGraphErrors(file1, "%lg %*s %*s %lg %lg");
TGraphErrors *gr1 = new TGraphErrors(file2, "%lg %*s %*s %lg %lg");
TGraph *gr2 = new TGraph();
gr2->SetPoint(0, 50., 3.70);


gr->SetMarkerColor(4);
gr->SetMarkerStyle(21);

gr1->SetMarkerColor(2);
gr1->SetMarkerStyle(21);

gr2->SetMarkerColor(6);
gr2->SetMarkerStyle(21);

mg->Add(gr);
mg->Add(gr1);
mg->Add(gr2);


mg->GetXaxis()->SetTitle("Neutron number (N)");
mg->GetYaxis()->SetTitle("Resonance spacing D_{0} (keV)");
mg->SetTitle("Neutron number (N) versus Resonance spacing D_{0}");


mg->Draw("ALP");

auto legend = new TLegend(0.8,0.8,0.9,0.9);
legend->AddEntry(gr, "Sr","lp");
legend->AddEntry(gr1,"Zr","lp");
legend->AddEntry(gr2,"Y","p");
legend->Draw();

gPad->Update();
gPad->Modified();
}
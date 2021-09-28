void plot(const char* file1, const char* file2){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 200,10,600,400);
c1->SetLogy();

TMultiGraph *mg = new TMultiGraph("mg","Energy (MeV) versus Reaction rate (mb)");

TGraphErrors *gr = new TGraphErrors(file1, "%lg %lg %lg");
TGraph *gr1 = new TGraph(file2, "%lg %lg %*s");
TGraph *gr2 = new TGraph(file2, "%lg %*s %lg");

// Options
gr->SetMarkerColor(2);
gr->SetMarkerStyle(20);

gr1->SetMarkerColor(4);
gr1->SetMarkerStyle(20); 

gr2->SetMarkerColor(6);
gr2->SetMarkerStyle(20); 

mg->Add(gr, "P");
mg->Add(gr1);
mg->Add(gr2);

mg->GetXaxis()->SetRangeUser(0,4);
mg->GetYaxis()->SetRangeUser(1E-5,1E6);


mg->GetXaxis()->SetTitle("Energy (MeV)");
mg->GetYaxis()->SetTitle("Reaction Rate (mb)");

auto legend = new TLegend(0.8,0.8,0.9,0.9);
legend->AddEntry(gr, "EXFOR Data","p");
legend->AddEntry(gr1,"TALYS Rate","lp");
legend->AddEntry(gr2,"MACS","p");


//Draw


mg->Draw("APL");
legend->Draw();

gPad->Modified();
gPad->Update();

}
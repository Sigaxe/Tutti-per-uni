
public class Data {

	private int giorno, mese, anno;
	
	
	public Data() {
		this.giorno = 1;
		this.mese = 1;
		this.anno = 1;
	}

	public Data(int giorno, int mese, int anno) {
		// TODO Auto-generated constructor stub
		if(checkDay(giorno) && checkMonth(giorno, mese)) {
			this.giorno = giorno;
			this.mese = mese;
			this.anno = anno;
		}
		else {
			System.out.println("Errore, data inserita non valida!");
		}
	}

	private boolean checkMonth(int giorno, int mese) {
		// TODO Auto-generated method stub
		if(mese < 1 || giorno > 12) return false;
		if(giorno == 31 && !(mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10 || mese == 12)) return false;
		if(mese == 2 && giorno > 28) return false;
		return true;
	}

	private boolean checkDay(int giorno) {
		// TODO Auto-generated method stub
		if(giorno < 1 && giorno > 31) return false;
		return true;
	}

	public int confronta(Data data) {
		// TODO Auto-generated method stub
		
		if(data.anno > this.anno) return -1;
		if(data.anno == this.anno) {
			if(data.mese > this.mese) return -1;
			if(data.mese == this.mese) {
				if(data.giorno > this.giorno) return -1;
				if(data.giorno == this.giorno) return 0;
			}
		}
		
		return 1;
	}

	@Override
	public String toString() {
		return this.giorno + "/" + this.mese + "/" + this.anno;
	}
	
	
}

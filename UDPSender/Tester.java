//Notice: This source code is still unlicensed.
package com.ltxom.demo.tester;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;

/**
 * Analyze the music scores(converted by David Hu) and convert it to an
 * integer(in the form of String) then send to the micro-controller via UDP
 * 
 * @author Tongxi Liu
 * @version 7/18/2017
 */
public class Tester {
	private ArrayList<boolean[]> notesList;

	public Tester(String path) throws IOException {
		File notesData = new File(path);
		BufferedReader br = new BufferedReader(new FileReader(notesData));
		notesList = new ArrayList<boolean[]>();
		analyzeData(br.readLine(), notesList);
		br.close();
	}

	private static void analyzeData(String line, ArrayList<boolean[]> notesList) {
		String[] list = line.split(",");
		boolean[] temp = new boolean[8];
		for (int i = 0; i < list.length; i++) {

			temp[i % 8] = list[i].contains("true") ? true : false;
			if (i % 8 == 0) {
				notesList.add(temp);
				temp = new boolean[8];
			}
			// list[i];
		}
	}

	public ArrayList<boolean[]> getNotesList() {
		return notesList;
	}

	private static int counter = 0;

	public static void main(String[] args) throws IOException, InterruptedException {
		int noteInterval = 50;

		Tester test = new Tester("/Users/ltxom/Documents/JAVA/Study/LTXOM_MAC/Demo/src/notes.data");
		ArrayList<boolean[]> notesList = test.getNotesList();

		InetAddress ia = InetAddress.getByName("192.168.1.92");
		System.out.println(ia.isReachable(3000));

		String data;

		DatagramSocket ds = new DatagramSocket(7000);
		DatagramPacket dp;

		while (counter != notesList.size()) {
			data = getNextLineValue(notesList);
			dp = new DatagramPacket(data.getBytes(), data.length(), ia, 2808);
			sendMessage(ds, dp);
			Thread.sleep(noteInterval);
		}

		ds.close();
	}

	public static String getNextLineValue(ArrayList<boolean[]> notesList) {
		boolean[] temp = notesList.get(counter++);
		String result = "";
		for (boolean b : temp) {
			result += b ? "1" : "0";
		}
		return Integer.valueOf(result, 2) + "";
	}

	public static boolean sendMessage(DatagramSocket ds, DatagramPacket dp) {
		try {
			ds.send(dp);
			System.out.println(dp.getLength());
		} catch (IOException e) {
			e.printStackTrace();
			return false;
		}
		return true;
	}

}

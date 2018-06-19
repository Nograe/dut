import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;
import javax.swing.ListSelectionModel.*;
import java.io.*;

public class GestionLivre extends JFrame implements ListSelectionListener {
   private JPanel contentPane = new JPanel();
   DefaultListModel<Livre> listModel;
   JList<Livre> liste;
   private static JTextField fieldTitre;
   private static JTextField fieldAuteur;
   private static JTextField fieldPrix;

   private static JLabel outputAuteur;
   private static JLabel outputPrix;

   public GestionLivre() {
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setVisible(true);
      setContentPane(contentPane);
      setTitle("Bibliotheque");
      setSize(500, 500);
      setLocationRelativeTo(null);
      // setResizable(false);
      listModel = new DefaultListModel<Livre>();
      liste = new JList<Livre>(listModel);
      liste.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
      liste.addListSelectionListener(this);

      miseEnPage();
   }

   public void miseEnPage() {
      contentPane.setLayout(new GridBagLayout());
      contentPane.setBackground(new Color(20, 170, 170));

      GridBagConstraints gbc = new GridBagConstraints();
      gbc.insets = new Insets(5, 5, 5, 5);
      gbc.gridx = gbc.gridy = 0;
      JLabel titre = new JLabel("Titre");
      contentPane.add(titre, gbc);

      gbc.gridx++;
      JLabel auteur = new JLabel("Auteur");
      contentPane.add(auteur, gbc);

      gbc.gridx++;
      JLabel prix = new JLabel("Prix");
      contentPane.add(prix, gbc);

      gbc.gridy++;
      gbc.gridx++;
      JButton ajouter = new JButton("Ajouter");
      contentPane.add(ajouter, gbc);
      ajouter.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            ajouterLivre();
         }
      });

      gbc.gridx = 0;
      fieldTitre = new JTextField(10);
      fieldTitre.setMinimumSize(new Dimension(150, 24));
      contentPane.add(fieldTitre, gbc);

      gbc.gridx++;
      fieldAuteur = new JTextField(10);
      fieldAuteur.setMinimumSize(new Dimension(100, 24));
      contentPane.add(fieldAuteur, gbc);

      gbc.gridx++;
      fieldPrix = new JTextField(10);
      fieldPrix.setMinimumSize(new Dimension(100, 24));
      contentPane.add(fieldPrix, gbc);

      gbc.gridx = 0;
      gbc.gridy = 2;
      gbc.gridwidth = 2;
      gbc.gridheight = 5;
      JScrollPane scroll = new JScrollPane(liste);
      scroll.setPreferredSize(new Dimension(200, 300));
      contentPane.add(scroll, gbc);

      gbc.gridx = 2;
      gbc.gridy = 2;
      gbc.gridwidth = 2;
      gbc.gridheight = 1;
      outputAuteur = new JLabel("Auteur: ");
      contentPane.add(outputAuteur, gbc);
      gbc.gridy++;
      outputPrix = new JLabel("Prix: ");
      contentPane.add(outputPrix, gbc);

      gbc.gridx = 2;
      gbc.gridy = 4;
      gbc.gridwidth = 2;
      gbc.gridheight = 1;
      JButton save = new JButton("Sauvegarder");
      save.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            try {
               save();
            } catch (FileNotFoundException | UnsupportedEncodingException e1) {
               e1.printStackTrace();
            }
         }
      });
      contentPane.add(save, gbc);
      gbc.gridy++;
      JButton load = new JButton("Charger");
      load.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            try {
               load();
            } catch (IOException e1) {
               e1.printStackTrace();
            }
         }
      });
      contentPane.add(load, gbc);

      contentPane.validate();
      contentPane.repaint();
   }

   public void ajouterLivre() {
      if(fieldTitre.getText().isEmpty() || fieldAuteur.getText().isEmpty() || fieldPrix.getText().isEmpty()) return;
      String titre = fieldTitre.getText();
      String auteur = fieldAuteur.getText();
      float prix = Float.parseFloat(fieldPrix.getText());
      listModel.addElement(new Livre(titre, auteur, prix));
      fieldTitre.setText(null);
      fieldAuteur.setText(null);
      fieldPrix.setText(null);
   }

   public void valueChanged(ListSelectionEvent e) {
      int maxIndex = listModel.getSize();
      for (int i = 0; i < maxIndex; i++) {
         if (liste.isSelectedIndex(i)) {
            outputAuteur.setText("Auteur: "+listModel.getElementAt(i).getAuteur());
            outputPrix.setText("Prix: "+listModel.getElementAt(i).getPrix());
         }
      }
      repaint();
   }

   public void save() throws FileNotFoundException, UnsupportedEncodingException {
      PrintWriter writer = new PrintWriter("livres.save", "UTF-8");
      int maxIndex = listModel.getSize();
      for (int i = 0; i < maxIndex; i++) {
         writer.println(listModel.getElementAt(i).getTitre());
         writer.println(listModel.getElementAt(i).getAuteur());
         writer.println(listModel.getElementAt(i).getPrix());
      }
      writer.close();
   }

   public void load() throws IOException {
      listModel.removeAllElements();
      BufferedReader load = new BufferedReader(new FileReader("livres.save"));
      String titre;
      String auteur;
      float prix;

      String line;
      while((line = load.readLine()) != null) {
         titre = line;
         auteur = load.readLine();
         prix = Float.parseFloat(load.readLine());
         listModel.addElement(new Livre(titre, auteur, prix));
      }
      load.close();
   }
}

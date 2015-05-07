class CreateClients < ActiveRecord::Migration
  def change
    create_table :clients do |t|
      t.string :first_name
      t.string :last_name
      t.string :email
      t.string :company
      t.string :project
      t.string :phone

      t.timestamps null: false
    end
  end
end

CREATE TABLE emp(
   empname text not null,
   salary integer
);

CREATE TABLE emp_audit(
   operation char(1) NOT NULL,
   stamp timestamp NOT NULL,
   userid text NOT NULL,
   empname text NOT NULL,
   salary integer
);

CREATE OR REPLACE function process_emp_audit() RETURNS TRIGGER AS $emp_audit$
BEGIN
IF (TG_OP = 'DELETE') THEN
INSERT INTO emp_audit SELECT 'D', now(), user, OLD.*;
RETURN OLD;
ELSEIF (TG_OP = 'UPDATE') THEN
INSERT INTO emp_audit SELECT 'U', now(), user, NEW.*;
RETURN NEW;
ELSEIF (TG_OP = 'INSERT') THEN
INSERT INTO emp_audit SELECT 'I', now(), user, NEW.*;
RETURN NEW;
END IF;
RETURN NULL;
END;
$emp_audit$ LANGUAGE plpgsql;

CREATE TRIGGER emp_audit
AFTER INSERT OR UPDATE OR DELETE ON emp
FOR EACH ROW EXECUTE PROCEDURE process_emp_audit();
